#include<map>
#include<cstdio>
#include<string>

using namespace std;

static const int WORD_SIZE = 4;

typedef enum{
    CGOBAL_VAR,
    CGOBAL_CONST_VAR,
    CARRAY,
    CLOCAL_VAR,
    CLOCAL_CONST_VAR,
    CFUNCTIONCALL
} ctx_t;


class Context{
private:
    map<string,int> stack_offset;
    map<string,int> var_label;
    int cur_offset;
    int label_count;
public:
    ctx_t cur_type;
    string cur_var_name;
    Context(){
        stack_offset.clear();
        var_label.clear();
        cur_offset = -4;
        label_count = 3;
    }
    int get_offset(string& var){
		if(!stack_offset.count(var)){
			return -1;
		}
        return stack_offset[var];
    }

    bool set_offset(string& var){
    	if(stack_offset.count(var)) return false;
        stack_offset[var] = cur_offset;
        cur_offset -= WORD_SIZE;
        return true;
    }

    int get_label(string& var){
		if(!var_label.count(var)){
			fprintf(stderr,"label: %s not exist\n", var.c_str());
            exit(-1);
		}
        return var_label[var];
    }

    bool set_label(string& var){
    	if(var_label.count(var)) return false;
        var_label[var] = label_count;
        label_count++;
        return true;
    }


    ~Context(){
    	stack_offset.clear();
        var_label.clear();
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