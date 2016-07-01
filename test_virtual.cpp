#include<string>
#include<iostream>
using namespace std;

class animal{
	public:
		virtual void say()=0;
		virtual void run() {
			cout << "running" <<endl;
		}
};
class dog:public animal{
	public:
		void say() {
			cout<<"wang wang ..."<<endl;
		}
		virtual void run() {
			cout << "dog running" <<endl;
		}
};
class jinmao:public dog{
	public:
		void say() {
			cout << "I am jinmao, wang wang ..." <<endl;
		}
		void run() {
			cout << "jinmao running" <<endl;
		}
};

void say(animal *a){
	a->say();
}
void run(animal *a){
	a->run();
}
void dog_run(dog *d){
	d->run();
}
int main(){
	say(new dog());
	say(new jinmao());
	run(new dog());
	run(new jinmao());
	dog_run(new jinmao());
	return 0;
}
/**
 * 多态玩的就是虚
 * 什么是多态？
 * 函数的形参中定义基类的情况，当然，这里的基类不一定是爷爷类，父亲类也可以，当实际调用时传递的如果是子类，那么，运行时会检查要调用的类的方法在基类（因为形参是基类，所以要参考基类）中是否virtual的，如果不是virtual的，则直接执行基类中的定义（即使当前确实是子类的实例，也不会执行子类的该方法，换言之，就是不允许覆盖，这就是virtual存在的意义，某些语言是直接覆盖的，没法选择不覆盖），如果是virtual的，则根据继承链向下检查，直到查到该方法的最后一个实现，哪怕继承链中的某些子类没有明确写virtual关键字也没关系（换言之，virtual属性是自动、强制继承的）；具体实现上可能不是一个一个查，但至少逻辑上是这样的
 */
