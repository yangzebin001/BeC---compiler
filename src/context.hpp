#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<set>

using namespace std;

const int WORD_SIZE = 4;

typedef enum{
    CGOBAL_VAR,
    CGOBAL_CONST_VAR,
    CGOBAL_ARRAY,
    CARRAY,
    CLOCAL_VAR,
    CLOCAL_CONST_VAR,
    CFUNCTIONCALL,
    CARRAY_DECL,
    CLVAL,
    CARRAY_ELE,
    CDIRECTDECL,
    CRETURN,
    CSINGLE,
    CGT,
    CLT,
    CGE,
    CLE,
    CEQ,
    CNE,
    CAND,
    COR,
    CIF,
    CWHILE
} ctx_t;


class Scope{
private:
    map<string,int> var_label;
    map<string,int> stack_offset;
    map<string,vector<int> > array_layers;
    set<string> is_def_array;
public:
    Scope* father;

    Scope(){
        var_label.clear();
        stack_offset.clear();
        array_layers.clear();
        is_def_array.clear();
        father = NULL;
    }

    int get_offset(string var){

		if(!stack_offset.count(var)){
			return 0;
		}
        return stack_offset[var];
    }

    bool set_offset(string var, int &cur_offset, int size){

    	if(stack_offset.count(var)) return false;
        cur_offset -= WORD_SIZE*size;
        stack_offset[var] = cur_offset+WORD_SIZE;
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

    bool set_array_layers(string name, vector<int> vec){
    	if(array_layers.count(name)) return false;
        array_layers[name] = vec;
        return true;
	}
	
	bool get_array_layers(string name, vector<int> &vec){
        if(!array_layers.count(name)) return false;
    	vec = array_layers[name];
        return true;
    }

    bool set_def_array(string name){
        if(is_def_array.count(name)) return false;
        is_def_array.insert(name);
        return true;
    }

    bool get_def_array(string name){
        if(!is_def_array.count(name)) return false;
        return true;
    }

    ~Scope(){
        var_label.clear();
        stack_offset.clear();
        array_layers.clear();
        is_def_array.clear();
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
    vector<int> cur_array_layers;
    int cur_array_index;
    bool cur_var_disload;
    int cur_return_label;

    Context(){
        cur_offset = -8;
        label_count = 3;
        scope = NULL;
        scopeID = 1;
        cur_array_index = 0;
        cur_var_disload = false;
        cur_return_label = 0;
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
    	return scope->set_offset(var, cur_offset, 1);
    }


    bool set_def_array(string name){
        return scope->set_def_array(name);
    }

    bool get_def_array(string name){
        Scope* now = scope;
        while(now != NULL){
            bool ll = now->get_def_array(name);
            if(ll) return true;
			else{
                int ls = now->get_offset(name);
                if(ls != 0) return false;
            }
            now = now->father;
        }
        return false;
    }

    bool set_assign_offset(string var, int size){
        return scope->set_offset(var, cur_offset, size);
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


    bool set_array_layers(string name, vector<int> vec){
    	if(scope == NULL) return false;
    	return scope->set_array_layers(name,vec);
	}
	
	bool get_array_layers(string name, vector<int> &vec){
        Scope* now = scope;
        while(now != NULL){
            bool ll = now->get_array_layers(name,vec);
			if(ll){
                return ll;
            }
            now = now->father;
        }
        return false;
	}

    string get_unique_temp_stack_name(string name){
        return name + to_string(cur_offset);
    }

    ~Context(){

        delete scope;
	}

};
class GobalContext{

private: 
    map<string, string> const_value;
    map<string, int> var_label;
    map<string,vector<int> > array_layers;
    map<string, int>::iterator it;
    int label_count;

public:

    vector<pair<string, int>> if_false_labels;
    vector<pair<string, int>> if_true_labels;
    vector<pair<string, int>> while_start_labels;
    vector<pair<string, int>> while_false_labels;

    GobalContext(){
        const_value.clear();
        this->label_count = 3;
        if_false_labels.clear();
        if_true_labels.clear();
    }


    string get_const_value(string var){
		if(!const_value.count(var)){
			fprintf(stderr,"const value: %s not exist\n", var.c_str());
            return "";
		}
        return const_value[var];
    }

    bool set_const_value(string name, string value){
    	if(const_value.count(name)) return false;
        const_value[name] = value;
        return true;
    }


    int get_label(string var){
		if(!var_label.count(var)){
			return -1;
		}
        return var_label[var];
    }

    bool set_label(string var){
    	if(var_label.count(var)) return false;
        var_label[var] = label_count;
        label_count++;
        return true;
    }

    int set_if_label(string var){
        int t = label_count;
        set_label(var+to_string(label_count));
        return label_count;
    }

    string get_if_label(string var, int label){
        return var+to_string(label);
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

    bool set_array_layers(string name, vector<int> vec){
        if(array_layers.count(name)) return false;
    	array_layers[name] = vec;
        return true;
	}
	
	bool get_array_layers(string name, vector<int> &vec){
        if(!array_layers.count(name)) return false;
        vec = array_layers[name];
        return true;
	}

    ~GobalContext(){
    	const_value.clear();
        var_label.clear();
	}

};