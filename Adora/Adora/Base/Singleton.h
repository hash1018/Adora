

#ifndef _SINGLETON_H
#define _SINGLETON_H


/*
****How to use DeclareSingleton macro.

class Example {

DeclareSingleton(Example)

private:
int var;

public:
void setVar(int var) { this->var = var; }

public:
inline int getVar() const { return this->var; }

};
****Declare varable and some functions and implement.
****Singleton Constructor,Destructor, and getInstance method will be declared automatically.
****just implement them.
*/
#define DeclareSingleton(className)\
\
private:\
     className();\
     ~className();\
public:\
     static className* getInstance(){\
\
     static className instance;\
     return &instance;\
     }\

#endif //_SINGLETON_H
