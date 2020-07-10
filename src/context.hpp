#include<map>
#include<cstdio>
#include<string>

using namespace std;

const int WORD_SIZE = 4;

typedef enum{
    CGOBAL_VAR,
    CGOBAL_CONST_VAR,
    CARRAY,
    CLOCAL_VAR,
    CLOCAL_CONST_VAR,
    CFUNCTIONCALL
} ctx_t;


class Scope{
private:
    map<string,int> var_label;
    map<string,int> stack_offset;
public:
    Scope* father;

    Scope(){
        var_label.clear();
        father = NULL;
    }

    int get_offset(string var){

		if(!stack_offset.count(var)){
			return 0;
		}
        return stack_offset[var];
    }

    bool set_offset(string var, int &cur_offset){

    	if(stack_offset.count(var)) return false;
        stack_offset[var] = cur_offset;
        cur_offset -= WORD_SIZE;
        return true;
    }

    int get_label(string var){
		if(!var_label.count(var)){
			return -1;
		}
        return var_label[var];
    }

    bool set_label(string var, int &label_count){
    	if(var_label.count(var)) return false;
        var_label[var] = label_count;
        label_count++;
        return true;
    }

    ~Scope(){
        stack_offset.clear();
        var_label.clear();
    }

};

class Context{
private:
    
    Scope* scope;
    int cur_offset;
    int label_count;
    int scopeID;
public:
    ctx_t cur_type;
    string cur_var_name;

    Context(){
        cur_offset = -4;
        label_count = 3;
        scope = NULL;
        scopeID = 1;
    }

    int get_offset(string var){
        Scope* now = scope;
        while(now != NULL){
            int ll = now->get_offset(var);
			if(ll != 0){
                return ll;
            }
            now = now->father;
        }
        return 0;
    }
		

    bool set_offset(string var){

    	return scope->set_offset(var,cur_offset);
    }

    int get_label(string var){
        Scope* now = scope;
        while(now != NULL){
            int ll = now->get_label(var);
			if(ll != -1){
                return ll;
            }
            now = now->father;
        }
        return -1;
    }

    bool set_label(string var){
        if(scope == NULL) return false;
    	return scope->set_label(var,label_count);
    }

    void new_scope(){
        Scope* new_scope = new Scope();
        new_scope->father = scope;
        scope = new_scope;
        scopeID++;
    }

    void delete_scope(){
        Scope* now = scope;
        scope = scope->father;
        delete now;
    }

    ~Context(){

        delete scope;
	}

};
class GobalContext{

private: 
    map<string, string> const_value;
    map<string, int> var_label;
    map<string, int>::iterator it;
    int label_count;

public:
    GobalContext(){
        const_value.clear();
        this->label_count = 3;
    }
    string get_const_value(string& var){
		if(!const_value.count(var)){
			fprintf(stderr,"const value: %s not exist\n", var.c_str());
            return "";
		}
        return const_value[var];
    }

    bool set_const_value(string& name, string& value){
    	if(const_value.count(name)) return false;
        const_value[name] = value;
        return true;
    }


    int get_label(string& var){
		if(!var_label.count(var)){
			return -1;
		}
        return var_label[var];
    }

    bool set_label(string& var){
    	if(var_label.count(var)) return false;
        var_label[var] = label_count;
        label_count++;
        return true;
    }

    void init_label_for(){
        this->it = var_label.begin();
    }

    bool get_next_label(string &tmp, int &label){
        if(this->it == var_label.end()){
            return false;
        }
        tmp = this->it->first;
        label = this->it->second;
        ++(this->it);
        return true;
    }

    ~GobalContext(){
    	const_value.clear();
        var_label.clear();
	}

};