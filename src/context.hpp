#include<map>
#include<cstdio>
#include<string>

using namespace std;

static const int WORD_SIZE = 4;

class Context{
private:
    map<string,int> stack_offset;
    int cur_offset;
public:
    Context(){
        stack_offset.clear();
        cur_offset = -4;
    }
    int get_offset(string& var){
		if(!stack_offset.count(var)){
			fprintf(stderr,"%s not exist\n", var.c_str());
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

    ~Context(){
    	stack_offset.clear();
	}

};