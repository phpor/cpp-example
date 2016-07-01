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
