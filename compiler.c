#include "str.h"
/// @brief that function of compiler 
struct function
{
    //command.str
    str commandName;
    //that function do f
    void(*__call__)(str*);
};
//set functions var
struct {function* f=(function*)malloc(100000*sizeof(function));size_t length = 0;}functions;
/// @brief that add function for functions
/// @param f that function will add it
void addFunction(function f){functions.f[functions.length++]=f;}
/// @brief that function call function by nabe
/// @param fun that name of function
/// @param elements that elements of function
int doFunction(str fun,str* elements)
{/*forloop*/for (int i = 0; i < functions.length; i++) \
    /*set return*/\
if(strcmp(functions.f[i].commandName.c_str,fun.c_str)==0) {functions.f[i].__call__(elements);/*return not error*/return 0;}
return 1;
}
/// @brief   that function  compile a string st       
/// @param code that str will code it
void compile(str code)
{
    //set str line & parameter
    str line=newstr() ,*allpremeters=newstrarray(),*parameters = newstrarray();
    //for loop
    for (size_t i = 0; i <=count(code,'\n'); i++)
    {
        //set line var
        line =toLines(code)[i];
            //parameter var
        allpremeters =superate(line,' ');
        //for loop
        for (size_t j = 0; j <=count(line,' '); j++) parameters[j-1]=allpremeters[j];
        //set function line by line
        doFunction(allpremeters[0],parameters);
    }
}