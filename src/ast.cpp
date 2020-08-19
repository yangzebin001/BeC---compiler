#include "ast.h"
#include "ast_helper.h"



void Program::codeGen(const char* in_file_name, const char* out_file_name){
    init_assembly(in_file_name, out_file_name);
    
    // store global const var and array
    for(int i = 0; i < constVarDecls.size(); i++){
        for(int j = 0; j < constVarDecls[i]->constVarDefList.size(); j++){
            //const var
            if(constVarDecls[i]->constVarDefList[j]->lval->type != ARRAYELEMENT){
                string var_name = get_lval_name(constVarDecls[i]->constVarDefList[j]->lval);
                string var_val = get_var_value((AddExpression*)constVarDecls[i]->constVarDefList[j]->initVal->exp);
                // cout << var_name << ":" << var_val << endl;
                global_ctx->set_const_value(var_name, var_val);

            }else{
            //const array treat as global array
                if(i == 0 && j == 0){
                    emit_text();
                    emit_data();
                }

                ArrayElement* now_arr_ele = (ArrayElement*)constVarDecls[i]->constVarDefList[j]->lval;
                InitVal* initVal = (InitVal*)constVarDecls[i]->constVarDefList[j]->initVal;

                // new ArrayDecl node for gen array code
                ArrayDecl* now_arrDecls = new ArrayDecl(now_arr_ele, initVal);

                int ele_number = get_array_element_number(now_arrDecls);
                string array_name = get_array_name(now_arrDecls->arrayElement);
                
                // cal array_layers info and insert to global_ctx
                vector<int> array_layers;
                get_array_element_number_vec(now_arrDecls,array_layers);
                global_ctx->set_array_layers(array_name, array_layers);
                
                //emit global_var_def
                emit_part_global_var_def(array_name.c_str(), ele_number*WORD_SIZE);
                
                vector<string> flat_array_eles;
                get_global_array_initval_from_vec(now_arrDecls->initVal, flat_array_eles, 0);
                
                global_ctx->array_initvals[array_name] = flat_array_eles;
                
                for(int i = 0; i < flat_array_eles.size(); i++){
                    emit_word(flat_array_eles[i].c_str());
                }

                // set necessary array info to global_ctx
                global_ctx->set_label(array_name);
                global_ctx->set_def_global_array(array_name);
            }
        }
    }



    // gen global var and array
    for(int i = 0; i < varDecls.size(); i++){
        // emit head info
        if(i == 0){
            emit_text();
            emit_data();
        }
        for(int j = 0; j < varDecls[i]->VarDefList.size(); j++){
            
            // gen var
            if(varDecls[i]->VarDefList[j]->type == DIRECTDECL){
                DirectDecl* now_varDecls = (DirectDecl*)varDecls[i]->VarDefList[j];
                
                if(now_varDecls->exp != NULL){
                    emit_global_var_def(now_varDecls->ident->id.c_str(), get_var_value((AddExpression*)now_varDecls->exp).c_str());
                }
                else{
                    emit_global_var_decl(now_varDecls->ident->id.c_str(), 4);
                }
                
                global_ctx->set_label(now_varDecls->ident->id);

            // gen array
            }else if(varDecls[i]->VarDefList[j]->type == ARRAYDECL){
                ArrayDecl* now_arrDecls = (ArrayDecl*)varDecls[i]->VarDefList[j];
                int ele_number = get_array_element_number(now_arrDecls);
                string array_name = get_array_name(now_arrDecls->arrayElement);
                
                 // cal array_layers info and insert to global_ctx
                vector<int> array_layers;
                get_array_element_number_vec(now_arrDecls,array_layers);
                global_ctx->set_array_layers(array_name, array_layers);

                // emit array def or decl
                if(now_arrDecls->initVal != NULL){
                    emit_part_global_var_def(array_name.c_str(), ele_number*WORD_SIZE);
                    
                    vector<string> flat_array_eles;
                    get_global_array_initval_from_vec(now_arrDecls->initVal, flat_array_eles, 0);
                    
                    global_ctx->array_initvals[array_name] = flat_array_eles;
                    
                    for(int i = 0; i < flat_array_eles.size(); i++){
                        emit_word(flat_array_eles[i].c_str());
                    }

                }else{
                    emit_global_var_decl(array_name.c_str(), ele_number*WORD_SIZE);
                }

                // set necessary array info to global_ctx
                global_ctx->set_label(array_name);
                global_ctx->set_def_global_array(array_name);
            }
        }
    }



    // gen function
    for(int i = 0; i < funcDefs.size(); i++){
        if(i == 0){
           emit_text();
        }
        // new context for every function
        Context* funcxt = new Context();
        // new top scope
        funcxt->new_scope();
        // gen function content
        funcDefs[i]->codeGen(*funcxt);
        funcxt->delete_scope();
        delete funcxt;
    }

    //gen var and array lable
    emit_text();
    string tmp = "";
    int label_idx = 1;
    global_ctx->init_label_for();
    while(global_ctx->get_next_label(tmp,label_idx)){
        // emit global var lable
        if(tmp.find("label_") != 0){
            emit_global_var_lable(get_global_label(label_idx).c_str(), tmp.c_str());

        }
    }

}

void FunctionDef::codeGen(Context &ctx){
    printf("gen FunctionDef\n");
    // emit function header
    emit_function_prologue2(id->id.c_str());

    // set return lable for current function
    int end_label = global_ctx->set_if_label("label_RETURN");
    ctx.cur_return_label = end_label;

    // init stack_point
    int stack_point = 4;


    for(int i = 0; i < ParamList.size(); i++){
        // param is var
        if(ParamList[i]->lval->type == IDENT){
            //gen var formal param
            DirectDecl *d = new DirectDecl((Ident*)ParamList[i]->lval, NULL);
            string ident = get_lval_name(ParamList[i]->lval);
            d->codeGen(ctx);

            if(i < 4){
                emit_instr_format("str", "r%d, [fp, #%d]", i, ctx.get_offset(ident));
            }else{
                emit_instr_format("ldr", "r6, [fp, #%d]", stack_point);
                emit_instr_format("str", "r6, [fp, #%d]", ctx.get_offset(ident));
                stack_point += WORD_SIZE;
            }

        // param is array
        }else{
            vector<int> array_layers;
            string ident = get_lval_name(ParamList[i]->lval);
            ArrayDecl* now_arrDecls = new ArrayDecl((ArrayElement*)ParamList[i]->lval, NULL);
            get_array_element_number_vec(now_arrDecls,array_layers);
            ctx.set_array_layers(ident, array_layers);
            ctx.set_offset(ident);


            if(i < 4){
                emit_instr_format("str", "r%d, [fp, #%d]", i, ctx.get_offset(ident));
            }else{
                emit_instr_format("ldr", "r6, [fp, #%d]", stack_point);
                emit_instr_format("str", "r6, [fp, #%d]", ctx.get_offset(ident));
                stack_point += WORD_SIZE;
            }
        }
    }

    // gen block content
    block->codeGen(ctx);
    
    // gen return label
    emit_label(global_ctx->get_if_label("label_RETURN", end_label).c_str());
    // gen function footer
    emit_function_epilogue2(id->id.c_str());
}

void Expression::codeGen(Context &ctx){
    printf("Expression\n");
}

void Statement::codeGen(Context &ctx){
    printf("Statement\n");
}

void BinaryOpExpression::codeGen(Context &ctx){
    printf("BinaryOpExpression\n");
}

void Block::codeGen(Context &ctx){
    // gen every statementList
    for(int i = 0; i < statementList.size(); i++){
        statementList[i]->codeGen(ctx);
    }
}

void RETURNStatement::codeGen(Context &ctx){
    printf("gen returnstatement\n");

    if(exp != NULL){
        ctx.cur_type = CRETURN;
        exp->codeGen(ctx);
        emit_instr_format("mov","r0, r3");
    }
    
    emit_instr_format("b","%s", global_ctx->get_if_label("label_RETURN", ctx.cur_return_label).c_str());
}

void AddExpression::codeGen(Context &ctx){
    printf("gen AddExpression\n");

    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);
    }else{
        // gen lhs
        lhs->codeGen(ctx);

        // temporarily save var to stack
        string new_tmp = ctx.get_unique_temp_stack_name("add");
        int offset = ctx.set_offset(new_tmp);
        emit_instr_format("sub", "sp, sp, #%d", WORD_SIZE);
        emit_instr_format("str", "r3, [fp, #%d]", ctx.get_offset(new_tmp));
        
        // gen rhs
        rhs->codeGen(ctx);
        
        //emit add/sub instr
        emit_instr_format("ldr", "r7, [fp, #%d]", ctx.get_offset(new_tmp));
        if(op->op == "+"){
            emit_instr_format("add", "r3, r7");
        }else if(op->op == "-"){
            emit_instr_format("sub", "r3, r7, r3");
        }
    }
}

void MulExpression::codeGen(Context &ctx){
    printf("gen MulExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);
    }else{
        // gen lhs
        lhs->codeGen(ctx);
        
        // temporarily save var to stack
        string new_tmp = ctx.get_unique_temp_stack_name("mul");
        int offset = ctx.set_offset(new_tmp);
        emit_instr_format("sub", "sp, sp, #%d", WORD_SIZE);
        emit_instr_format("str", "r3, [fp, #%d]", ctx.get_offset(new_tmp));
        
        //gen rhs
        rhs->codeGen(ctx);

        //emit mul instr or call __aeabi_idiv/__aeabi_idivmod function
        emit_instr_format("ldr", "r7, [fp, #%d]", ctx.get_offset(new_tmp));
        if(op->op == "*"){
            emit_instr_format("mul", "r3, r7");
        }
        else if(op->op == "/"){
            emit_instr_format("mov", "r1, r3");
            emit_instr_format("mov", "r0, r7");
            emit_instr_format("bl", "__aeabi_idiv");
            emit_instr_format("mov", "r3, r0");
        }else if(op->op == "%"){
            emit_instr_format("mov", "r1, r3");
            emit_instr_format("mov", "r0, r7");
            emit_instr_format("bl", "__aeabi_idivmod");
            emit_instr_format("mov", "r3, r1");
        }
    }
}

void PrimaryExpression::codeGen(Context &ctx){
    printf("gen PrimaryExpression\n");
    if(lval != NULL){

        ctx.cur_type = CLVAL;
        lval->codeGen(ctx);

        // is array name
        if(ctx.cur_type == CARRAY_ELE){
            bool is_const_array = false;
            string lval_name = ctx.cur_var_name;

            int array_offset = ctx.get_offset(lval_name);
            if(array_offset != 0){
                bool is_def_arr = ctx.get_def_array(lval_name);
                // local def array
                if(is_def_arr){
                    if(abs(array_offset) > 255){
                        emit_instr_format("ldr", "r6, =%d", -array_offset);
                        emit_instr_format("sub", "r1, fp, r6");
                    }else{
                        emit_instr_format("sub", "r1, fp, #%d", -array_offset);
                    }
                // formal param array
                }else{
                    emit_instr_format("ldr", "r1, [fp, #%d]", array_offset);
                }
            }else{
                int label  = global_ctx->get_label(lval_name);
                //global array
                if(label != -1){
                    emit_instr_format("ldr", "r1, %s", get_global_label(label).c_str());
                }else{
                //global const array
                    is_const_array = true;
                    emit_instr_format("ldr", "r1, =%s", global_ctx->get_const_value(lval_name).c_str());
                }
            }

            // as right value 
            // need to load to r3 register
            if(ctx.cur_var_disload == false && is_const_array == false){
                emit_instr_format("ldr", "r3, [r1, r9]");
            }
        }

        

    }else if(exp != NULL){
        exp->codeGen(ctx);
    }else{
        // constant number
        emit_instr_format("ldr","r3, =%s",number.c_str());
    }
}

void UnaryExp::codeGen(Context &ctx){
    printf("gen UnaryExp\n");
    if(primaryExp != NULL){
        primaryExp->codeGen(ctx);
    }else if(funcCall != NULL){
        funcCall->codeGen(ctx);
    }else if(unaryOp != NULL){
        unaryExp->codeGen(ctx);

        // negative op
        if(unaryOp->op == "-"){
            emit_instr_format("rsb", "r3, r3, #0");
        // nreverse op
        }else if(unaryOp->op == "!"){
            emit_instr_format("cmp", "r3, #0");
            emit_instr_format("moveq", "r3, #1");
            emit_instr_format("movne", "r3, #0");
            emit_instr_format("uxtb", "r3, r3");
        }
    }
}

void FunctionCall::codeGen(Context &ctx){
    printf("gen FunctionCall\n");

    ctx.cur_type = CFUNCTIONCALL;
    // init stack_point
    int stack_point = 0;    
    // allocate stack space for ParamList > 4 
    if(ParamList.size() > 4){
        emit_instr_format("sub", "sp, sp, #%d", (ParamList.size()-4)*WORD_SIZE);
    }

    // gen ParamList
    for(int i = 4 ; i < ParamList.size(); i++){
        ParamList[i]->codeGen(ctx);
        emit_instr_format("str", "r3, [sp, #%d]", stack_point);
        stack_point += WORD_SIZE;
    }
    for(int i = 0; i < ParamList.size() && i < 4; i++){
        ParamList[i]->codeGen(ctx);
        if(i == 2){
            emit_instr_format("mov", "r7, r3");
        }else{
            emit_instr_format("mov", "r%d, r3",i);  
        }
    }
    if(ParamList.size() >= 2){
        emit_instr_format("mov", "r2, r7");
    }
    emit_instr_format("bl","%s",id->id.c_str());
    emit_instr_format("mov", "r3, r0");
}



void RelExpression::codeGen(Context &ctx){
    printf("gen RelExpression\n");

    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);
        ctx.cur_type = CSINGLE;
    }else{
        //gen lhs
        lhs->codeGen(ctx);

        // temporarily save var to stack
        string new_tmp = ctx.get_unique_temp_stack_name("mul");
        int offset = ctx.set_offset(new_tmp);
        emit_instr_format("sub", "sp, sp, #%d", WORD_SIZE);
        emit_instr_format("str", "r3, [fp, #%d]", ctx.get_offset(new_tmp));
       
        // gen rhs
        rhs->codeGen(ctx);

        emit_instr_format("ldr", "r7, [fp, #%d]", ctx.get_offset(new_tmp));
        emit_instr_format("cmp", "r7, r3");
        // record op type
        if(op->op == ">"){
            ctx.cur_type = CGT;
        }else if(op->op == "<"){
            ctx.cur_type = CLT;
        }else if(op->op == ">="){
            ctx.cur_type = CGE;
        }else if(op->op == "<="){
            ctx.cur_type = CLE;
        }
    }
}

void EqExpression::codeGen(Context &ctx){
    printf("gen EqExpression\n");
    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);
    }else{
        //gen lhs
        lhs->codeGen(ctx);

        // temporarily save var to stack
        string new_tmp = ctx.get_unique_temp_stack_name("mul");
        int offset = ctx.set_offset(new_tmp);
        emit_instr_format("sub", "sp, sp, #%d", WORD_SIZE);
        emit_instr_format("str", "r3, [fp, #%d]", ctx.get_offset(new_tmp));
        
        // gen rhs
        rhs->codeGen(ctx);
        
        emit_instr_format("ldr", "r7, [fp, #%d]", ctx.get_offset(new_tmp));
        emit_instr_format("cmp", "r7, r3");
        
        // record op type
        if(op->op == "=="){
            ctx.cur_type = CEQ;
        }else if(op->op == "!="){
            ctx.cur_type = CNE;
        }
    }
}

void LAndExpression::codeGen(Context &ctx){
    printf("gen LAndExpression\n");


    ctx_t cur_type = ctx.cur_type;
    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);  
    }else{
        // if statement
        if(cur_type == CIF){
            // get if label
            string end_label_name = (global_ctx->if_false_labels).back().first;
            int end_label = (global_ctx->if_false_labels).back().second;
            string true_label_name = (global_ctx->if_true_labels).back().first;
            int true_label = (global_ctx->if_true_labels).back().second;

            // gen lhs
            lhs->codeGen(ctx);
            //will print many time when LAndExpression's son also is LAndExpression
            if(ctx.cur_type == CSINGLE)
                emit_instr_format("cmp", "r3, #0");
            // emit rel instr
            write_rel_instr(ctx.cur_type, global_ctx->get_if_label(end_label_name, end_label));
            
            // gen rhs
            rhs->codeGen(ctx);
            if(ctx.cur_type == CSINGLE)
                emit_instr_format("cmp", "r3, #0");
            // emit rel instr    
            write_rel_instr(ctx.cur_type, global_ctx->get_if_label(end_label_name, end_label));
            
            ctx.cur_type = CAND;
        // while statement
        }else if(cur_type == CWHILE){

            string end_label_name =(global_ctx->while_false_labels).back().first;
            int end_label = (global_ctx->while_false_labels).back().second;
            
            lhs->codeGen(ctx);
            //will print many time when LAndExpression's son also is LAndExpression
            if(ctx.cur_type == CSINGLE)
                emit_instr_format("cmp", "r3, #0");
            
            write_rel_instr(ctx.cur_type, global_ctx->get_if_label(end_label_name, end_label));
            
            rhs->codeGen(ctx);
            
            if(ctx.cur_type == CSINGLE)
                emit_instr_format("cmp", "r3, #0");
            write_rel_instr(ctx.cur_type, global_ctx->get_if_label(end_label_name, end_label));
            
            ctx.cur_type = CAND;
        }
    }
}


void LOrExpression::codeGen(Context &ctx){
    printf("gen LOrExpression\n");
    ctx_t cur_type = ctx.cur_type;

    if(unaryExp != NULL){
        unaryExp->codeGen(ctx);
        if(ctx.cur_type == CSINGLE){
            emit_instr_format("cmp", "r3, #0");
        }

        if(cur_type == CIF){
            string end_label_name = global_ctx->if_false_labels.back().first;
            int end_label = global_ctx->if_false_labels.back().second;
            
            write_rel_instr(ctx.cur_type, global_ctx->get_if_label(end_label_name, end_label));
        }else if(cur_type == CWHILE){
            string end_label_name = global_ctx->while_false_labels.back().first;
            int end_label = global_ctx->while_false_labels.back().second;
            
            write_rel_instr(ctx.cur_type, global_ctx->get_if_label(end_label_name, end_label));
        }

    }else{
        if(cur_type == CIF){
            string end_label_name =(global_ctx->if_false_labels).back().first;
            int end_label = (global_ctx->if_false_labels).back().second;
            string true_label_name =(global_ctx->if_true_labels).back().first;
            int true_label = (global_ctx->if_true_labels).back().second;


            // add orfalse/orend labels
            int or_false_label = global_ctx->set_if_label("label_ORFALSE");
            (global_ctx->if_false_labels).push_back(make_pair("label_ORFALSE",or_false_label));
            int or_end_label = global_ctx->set_if_label("label_OREND");
            (global_ctx->if_true_labels).push_back(make_pair("label_OREND",or_end_label));
        

            lhs->codeGen(ctx);
            write_rel_instr_forward(ctx.cur_type, global_ctx->get_if_label(true_label_name, true_label));
            
            // goto true label position
            emit_instr_format("b", "%s", global_ctx->get_if_label(true_label_name, true_label).c_str());
            
            // emit orfalse
            emit_label(global_ctx->get_if_label("label_ORFALSE", or_false_label).c_str());
            (global_ctx->if_false_labels).pop_back();

            ctx.cur_type = CIF;
            rhs->codeGen(ctx);

            // emit orend label
            write_rel_instr(ctx.cur_type, global_ctx->get_if_label(end_label_name, end_label));

        }else if(cur_type == CWHILE){
            string end_label_name =(global_ctx->while_false_labels).back().first;
            int end_label = (global_ctx->while_false_labels).back().second;
            string true_label_name =(global_ctx->while_true_labels).back().first;
            int true_label = (global_ctx->while_true_labels).back().second;
            

            // add orfalse/orend labels
            int or_false_label = global_ctx->set_if_label("label_ORFALSE");
            (global_ctx->while_false_labels).push_back(make_pair("label_ORFALSE",or_false_label));
            int or_end_label = global_ctx->set_if_label("label_OREND");
            (global_ctx->while_true_labels).push_back(make_pair("label_OREND",or_end_label));


            lhs->codeGen(ctx);
            write_rel_instr_forward(ctx.cur_type, global_ctx->get_if_label(true_label_name, true_label));
            
            // goto true label position
            emit_instr_format("b", "%s", global_ctx->get_if_label(true_label_name, true_label).c_str());
            
            // emit orfalse
            emit_label(global_ctx->get_if_label("label_ORFALSE", or_false_label).c_str());
            (global_ctx->while_false_labels).pop_back();

            // gen rhs
            cur_type = CWHILE;
            rhs->codeGen(ctx);

            // emit orend label
            write_rel_instr(ctx.cur_type, global_ctx->get_if_label(end_label_name, end_label));
        }

    }
}

void ExpressionStatement::codeGen(Context &ctx){
    printf("gen ExpressionStatement\n");
    assert(exp != NULL);
    exp->codeGen(ctx);
}

void VarDecl::codeGen(Context &ctx){
    printf("gen VarDecl\n");
    for(int i = 0; i < VarDefList.size(); i++){
        VarDefList[i]->codeGen(ctx);
    }
}


void VarDef::codeGen(Context &ctx){
    printf("gen VarDef\n");
}

void DirectDecl::codeGen(Context &ctx){
    printf("gen DirectDecl\n");
    assert(ident != NULL);

    // gen var
    ctx.cur_type = CDIRECTDECL;

    // allocate stack space for ident
    bool offset_result = ctx.set_offset(ident->id);
    if(offset_result) {
        emit_instr_format("sub", "sp, sp, #%d", WORD_SIZE);
    }
    // def statement
    if(exp != NULL){
        exp->codeGen(ctx);
        emit_instr_format("str", "r3, [fp, #%d]", ctx.get_offset(ident->id));
    }
}

void ArrayDecl::codeGen(Context &ctx){
    ctx.cur_type = CARRAY_DECL;

    // get array size and name
    int number = get_array_element_number(this);
    string array_name = get_array_name(arrayElement);

    // set def array
    ctx.set_def_array(array_name);

    // allocate stack space for array
    bool offset_result = ctx.set_assign_offset(array_name,number);

    //set array layers info
    vector<int> array_layers;
    get_array_element_number_vec(this,array_layers);
    ctx.set_array_layers(array_name, array_layers);

    //call memset
    emit_instr_format("ldr", "r6, =%d", -ctx.get_offset(array_name));
    emit_instr_format("sub", "r0, fp, r6");
    emit_instr_format("mov", "r1, #0");
    emit_instr_format("ldr", "r2, =%d", number*WORD_SIZE);
    emit_instr_format("bl", "memset");

    // emit push array 
    if(offset_result) {
        emit_instr_format("sub", "sp, sp, #%d", number*WORD_SIZE);
    }
    if(abs(-ctx.get_offset(array_name)) > 255){
        emit_instr_format("ldr", "r6, =%d", -ctx.get_offset(array_name));
        emit_instr_format("sub", "r2, fp, r6");
    }else{
        emit_instr_format("sub", "r2, fp, #%d", -ctx.get_offset(array_name));

    }

    // gen initVal
    if(initVal != NULL){
        vector<Expression*> expList;
        get_global_array_initval(initVal, expList, 0);
        for(int i = 0; i < expList.size(); i++){
            expList[i]->codeGen(ctx);
            emit_instr_format("str", "r3, [r2, #%d]", i*WORD_SIZE);
        }
    }
}

void ConstVarDecl::codeGen(Context &ctx){
    printf("gen ConstVarDecl\n");
    for(int i = 0; i < constVarDefList.size(); i++){
        constVarDefList[i]->codeGen(ctx);
    }
}


void ConstVarDef::codeGen(Context &ctx){
    printf("gen ConstVarDef\n");
    if(lval->type == ARRAYELEMENT){
        ArrayDecl* constArrayDecl = new ArrayDecl((ArrayElement*)lval, initVal);
        constArrayDecl->codeGen(ctx);
    }else if(lval->type == IDENT){
        string var_name = get_lval_name(lval);
        string var_val = get_var_value((AddExpression*)initVal->exp);
        // set const value
        ctx.set_const_value(var_name, var_val);
    }
}


void Lval::codeGen(Context &ctx){
    printf("gen Lval\n");
}

void Ident::codeGen(Context &ctx){
    printf("gen Ident\n");

    ctx.cur_var_name = id;

    // get stack offset
    int offset = ctx.get_offset(id);
    
    //local var
    if(offset != 0){
        //local const var
        string local_offset = ctx.get_const_value(id);
        if(to_string(offset) == local_offset){
            emit_instr_format("ldr", "r3, =%d", offset);
        }else if(ctx.cur_var_disload == false){
            //local array
            if(ctx.get_def_array(id)){
                if(abs(offset) > 255){
                    emit_instr_format("ldr", "r6, =%d", -offset);
                    emit_instr_format("sub", "r3, fp, r6");
                }else{
                    emit_instr_format("sub", "r3, fp, #%d", -offset);
                }
                // emit_instr_format("sub", "r3, fp, #%d", -offset);
            }else{
                //local var
                emit_instr_format("ldr", "r3, [fp, #%d]", offset);

            }
        }
        ctx.cur_type = CLOCAL_VAR;
    }else{
        
        //global var
        int label = global_ctx->get_label(id);
        if(label != -1){
            emit_instr_format("ldr", "r2, %s", get_global_label(label).c_str());
            if(ctx.cur_var_disload == false){
                if(global_ctx->get_def_global_array(id)){
                    emit_instr_format("mov", "r3, r2");
                }else{
                    emit_instr_format("ldr", "r3, [r2]");
                }
            }
            ctx.cur_type = CGLOBAL_VAR;
        }else{
            //global const var
            string global_const_var = global_ctx->get_const_value(id);
            if(global_const_var != ""){
                emit_instr_format("ldr","r3, =%s",global_const_var.c_str());
            }else {
                fprintf(stderr,"cannot find : %s not def\n", id.c_str());
                exit(-1);
            }
        }
        
    }
}

void ArrayElement::codeGen(Context &ctx){

    // array direct needn't reach here
    printf("gen arrayElement\n");

    if(ctx.cur_type != CLVAL && ctx.cur_type != CARRAY_ELE) return;

    // if need to load to register
    bool cur_var_disload = ctx.cur_var_disload;
    ctx.cur_var_disload = false;

    string array_name = get_array_name(this);

    if(array->type == IDENT){
        
        // init array info
        ctx.cur_array_layers.push_back(vector<int>());

        ctx.cur_var_name = array_name;
        ctx.get_array_layers(array_name, ctx.cur_array_layers.back());

        if(ctx.cur_array_layers.back().size() == 0){
            global_ctx->get_array_layers(array_name, ctx.cur_array_layers.back());
        }

        ctx.cur_array_index = 1;
        
        index->codeGen(ctx);
        ctx.cur_var_name = array_name;
        ctx.cur_type = CARRAY_ELE;
        emit_instr_format("mov","r9, r3");
    }else{
        array->codeGen(ctx);

        // gen index 
        ctx.cur_var_name = array_name;
        index->codeGen(ctx);
        ctx.cur_var_name = array_name;
        ctx.cur_type = CARRAY_ELE;

        emit_instr_format("mov","r7, #%d",ctx.cur_array_layers.back()[ctx.cur_array_index]);
        emit_instr_format("mul","r9, r7");
        emit_instr_format("add","r9, r3");
        
        // array dimension + 1
        ctx.cur_array_index++;
    }
    
    // out this type ArrayElement node
    if(ctx.cur_array_index == ctx.cur_array_layers.back().size()){
        emit_instr_format("lsl","r9, r9, #%d", WORD_SIZE_WIDTH);
        ctx.cur_array_layers.pop_back();
        ctx.cur_var_disload = cur_var_disload;
    }
}

void Assignment::codeGen(Context &ctx){
    printf("gen Assignment\n");

    // exp after lval gen if type is arrayElement
    exp->codeGen(ctx);  //in r3

    emit_instr_format("mov", "r8, r3");

    ctx.cur_type = CLVAL;


    ctx.cur_var_disload = true;
    lval->codeGen(ctx); //in r2 or arrayElement scale in r1
    // rval need to load to register
    ctx.cur_var_disload = false;

    ctx_t lval_type = ctx.cur_type;
    string lval_name = ctx.cur_var_name;

    if(lval_type == CGLOBAL_VAR){
        emit_instr_format("str", "r8, [r2]");
    }else if(lval_type == CLOCAL_VAR){
        emit_instr_format("str", "r8, [fp, #%d]",  ctx.get_offset(lval_name));
    }else if(lval_type == CARRAY_ELE){

        int array_offset = ctx.get_offset(lval_name);
        if(array_offset != 0){
            bool is_def_arr = ctx.get_def_array(lval_name);
                if(is_def_arr){
                    if(abs(array_offset) > 255){
                        emit_instr_format("ldr", "r6, =%d", -array_offset);
                        emit_instr_format("sub", "r1, fp, r6");
                    }else{
                        emit_instr_format("sub", "r1, fp, #%d", -array_offset);

                    }
                }else{
                    emit_instr_format("ldr", "r1, [fp, #%d]", array_offset);
                }
            emit_instr_format("str", "r8, [r1, r9]");
        }else{
        //global array
            emit_instr_format("ldr", "r1, %s", get_global_label(global_ctx->get_label(lval_name)).c_str());
            emit_instr_format("str", "r8, [r1, r9]");
        }
    }
}

/** 
if false 
to label false
label true
true->gen
to label ifend
label false
false->gen
label ifend
**/
void IFStatement::codeGen(Context &ctx){
    printf("gen IFStatement\n");
    
    if(FALSEStmt == NULL){
        // add label
        int end_label = global_ctx->set_if_label("label_IFEND");
        int true_label = global_ctx->set_if_label("label_IFTRUE");
        (global_ctx->if_false_labels).push_back(make_pair("label_IFEND",end_label));
        (global_ctx->if_true_labels).push_back(make_pair("label_IFTRUE",true_label));
        
        // gen cond 
        ctx_t pre_type = ctx.cur_type;
        ctx.cur_type = CIF;
        exp->codeGen(ctx);
        ctx.cur_type = pre_type;

        // gen label_IFTRUE
        emit_label(global_ctx->get_if_label("label_IFTRUE", true_label).c_str());

        // gen true statement 
        pre_type = ctx.cur_type;
        ctx.cur_type = CIF;
        ctx.new_scope();
        TRUEStmt->codeGen(ctx);
        ctx.delete_scope();
        ctx.cur_type = pre_type;
        
        // gen label_IFEND
        emit_label(global_ctx->get_if_label("label_IFEND", end_label).c_str());


        // delete label
        (global_ctx->if_false_labels).pop_back();
        (global_ctx->if_true_labels).pop_back();

    }else if(FALSEStmt != NULL) {

        // add labels
        int false_label = global_ctx->set_if_label("label_IFFALSE");
        int true_label = global_ctx->set_if_label("label_IFTRUE");
        int end_label = global_ctx->set_if_label("label_IFEND");

        
        //store false label
        (global_ctx->if_false_labels).push_back(make_pair("label_IFFALSE",false_label));
        //store true label
        (global_ctx->if_true_labels).push_back(make_pair("label_IFTRUE",true_label));
        
        //cond
        ctx_t pre_type = ctx.cur_type;
        ctx.cur_type = CIF;
        exp->codeGen(ctx);
        ctx.cur_type = pre_type;
        
        // gen label_IFTRUE
        emit_label(global_ctx->get_if_label("label_IFTRUE", true_label).c_str());
        
        //gen true statement
        pre_type = ctx.cur_type;
        ctx.cur_type = CIF;
        ctx.new_scope();
        TRUEStmt->codeGen(ctx);
        ctx.delete_scope();
        ctx.cur_type = pre_type;

        // skip false area
        emit_instr_format("b", "%s", global_ctx->get_if_label("label_IFEND", end_label).c_str());
        emit_label(global_ctx->get_if_label("label_IFFALSE", false_label).c_str());
        
        //gen false statement
        pre_type = ctx.cur_type;
        ctx.cur_type = CIF;
        ctx.new_scope();
        FALSEStmt->codeGen(ctx);
        ctx.delete_scope();
        ctx.cur_type = pre_type;
        
        // gen label_IFEND
        emit_label(global_ctx->get_if_label("label_IFEND", end_label).c_str());
    
        // delete labels
        (global_ctx->if_false_labels).pop_back();
        (global_ctx->if_true_labels).pop_back();
    }

}

void BlockStatement::codeGen(Context &ctx){
    printf("gen BlockStatement\n");
    
    // to next block ---> new scope
    ctx.new_scope();
    block->codeGen(ctx);
    ctx.delete_scope();
}

/**
while_start
if false
to  label end
label while true
block 
b while_start
*/
void WHILEStatement::codeGen(Context &ctx){
    printf("gen WHILEStatement\n");

    int while_start = global_ctx->set_if_label("label_WHILESTART");
    int while_true = global_ctx->set_if_label("label_WHILETRUE");
    int end_label = global_ctx->set_if_label("label_WHILEEND");
    //store label_WHILESTART
    (global_ctx->while_start_labels).push_back(make_pair("label_WHILESTART",while_start));
    //store label_WHILETRUE
    (global_ctx->while_true_labels).push_back(make_pair("label_WHILETRUE",while_true));
    //store label_WHILEEND
    (global_ctx->while_false_labels).push_back(make_pair("label_WHILEEND",end_label));
    //while_start
    emit_label(global_ctx->get_if_label("label_WHILESTART", while_start).c_str());
    
    
    //cond
    ctx_t pre_type = ctx.cur_type;
    ctx.cur_type = CWHILE;
    exp->codeGen(ctx);
    ctx.cur_type = pre_type;

    // gen whiletrue label
    emit_label(global_ctx->get_if_label("label_WHILETRUE", while_true).c_str());
    
    pre_type = ctx.cur_type;
    ctx.cur_type = CWHILE;
    ctx.new_scope();
    stmt->codeGen(ctx);
    ctx.delete_scope();
    ctx.cur_type = pre_type;

    // b label_WHILESTART
    emit_instr_format("b", "%s", global_ctx->get_if_label("label_WHILESTART", while_start).c_str());
    // label_WHILEEND
    emit_label(global_ctx->get_if_label("label_WHILEEND", end_label).c_str());
    

    (global_ctx->while_start_labels).pop_back();
    (global_ctx->while_false_labels).pop_back();
    (global_ctx->while_true_labels).pop_back();
}


void BREAKStatement::codeGen(Context &ctx){
    printf("gen BREAKStatement\n");

    // nearest while_false_label
    string end_label_name =(global_ctx->while_false_labels).back().first;
    int end_label = (global_ctx->while_false_labels).back().second;
    emit_instr_format("b", "%s", global_ctx->get_if_label(end_label_name, end_label).c_str());
}

void CONTINUEStatement::codeGen(Context &ctx){
    printf("gen CONTINUEStatement\n");

    // nearest while_start_label
    string start_label_name =(global_ctx->while_start_labels).back().first;
    int start_label = (global_ctx->while_start_labels).back().second;
    emit_instr_format("b", "%s", global_ctx->get_if_label(start_label_name, start_label).c_str());
}