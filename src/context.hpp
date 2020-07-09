#include<map>
#include<cstdio>
#include<string>

using namespace std;

static const int WORD_SIZE = 4;

class Context{
private:
    map<string,int> stack_offset;
    map<string,int> var_lable;
    int cur_offset;
    int lable_count;
public:
    Context(){
        stack_offset.clear();
        var_lable.clear();
        cur_offset = -4;
        lable_count = 3;
    }
    int get_offset(string& var){
		if(!stack_offset.count(var)){
			fprintf(stderr,"offset: %s not exist\n", var.c_str());
            exit(-1);
		}
        return stack_offset[var];
    }

    bool set_offset(string& var){
    	if(stack_offset.count(var)) return false;
        stack_offset[var] = cur_offset;
        cur_offset -= WORD_SIZE;
        return true;
    }

    int get_lable(string& var){
		if(!stack_offset.count(var)){
			fprintf(stderr,"lable: %s not exist\n", var.c_str());
            exit(-1);
		}
        return var_lable[var];
    }

    bool set_lable(string& var){
    	if(var_lable.count(var)) return false;
        var_lable[var] = cur_offset;
        lable_count++;
        return true;
    }


    ~Context(){
    	stack_offset.clear();
        var_lable.clear();
	}

};

class GobalContext{

private: 
    map<string, string> const_value;

public:
    GobalContext(){
        const_value.clear();
    }
    string get_const_value(string& var){
		if(!const_value.count(var)){
			fprintf(stderr,"const value: %s not exist\n", var.c_str());
            exit(-1);
		}
        return const_value[var];
    }

    bool set_const_value(string& name, string& value){
    	if(const_value.count(name)) return false;
        const_value[name] = value;
        return true;
    }


    ~GobalContext(){
    	const_value.clear();
	}

};