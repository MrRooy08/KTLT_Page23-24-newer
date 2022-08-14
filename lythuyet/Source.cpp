#include <iostream>
using namespace std;
 
//void doSomeThing_static()
//{
//	static int s_value(0);
//	++s_value;
//	cout << s_value << endl;
//}
//
//int main()
//{
//	doSomeThing_static();
//	doSomeThing_static();
//	doSomeThing_static();
//	doSomeThing_static();
//	return 0;
//}

int a = 5;
int ham1(int k);         // hàm int k được khai báo biến k nhưng chưa có giá trị 

int main()
{
	
		int b=2,c;
/*lần 1*/		c = ham1(b);   //c=ham1(b) => c=ham1(k) và k=3 => c=ham1(3) và c=3
		cout << " \n " << a << "\t " << b << " \t " << c;
/*lần 2*/		b= ham1(c);    //Biến tĩnh được gọi lại 2 lần ham1(b) cho nên sẽ chạy 2 lần 
		cout << " \n " << a << "\t " << b << " \t " << c;

}

int ham1(int k) // ham1(b) lúc đầu khai báo chưa có giá trị cho nên vì vậy mà khi vào hàm main với biến cục bộ thì phải cần gán giá trị ( được gọi là đối số )
{    
	static int s = 1;
	a -= s;
	k += s;
	s++;
	cout << " \n ham1: " << a << " \t " << k << "\t" << s;
	return k;
}



/* In kết quả: 
  
  ham1 lần 1: 
  a=4   k=3   s=2  ( a=5 truyền vào s=1 lệnh a-=s => a=4 và lúc đầu k=1 với s=2 là do s++  )++( hàm truyền chạy vào main thì ham1 mang giá trị ham1(b) là bằng 2 mà vào int ham1(int k)
  thì b chính là k và k=2 và phép tính k+=s với s++ gán trước rồi tăng thì s=1 => k+=s là k=2+1=3 ) 

________________________________________________________

cout dòng 1: 
  a=4   b=2   c=3  ( hàm được truyền vào nên khi xuất ra thì a vẫn bằng 4)++( b được khai báo biến int b=2 nên b=2 )++( c thì = ham1(b) mà ham1(b) là ham1(k)=ham1(3) => c=3)

___________________________________________________________

 ham1 lần 2:
  a=2   k=5   s=3 ( tiếp tục hàm biến tĩnh static bị tăng lên 1 và int s=1 được xem như là int s=2 và bỏ qua dòng lệnh static int ) 
  ( vì vậy mà a=4 với lệnh a-=s => a=2 )++(k=3 thì lệnh k+=s =>k=5 )++( s++ gán trước rồi tăng thì nãy s đã được gán vào k nên giờ tăng lên => s=3 )

______________________________________________________________
cout dòng 2:
  a=2   b=5   c=3 ( hàm được truyền vào nên khi xuất ra thì a vẫn bằng 2) 
  (b = ham1(c) đồng với việc b=ham1(k) mà k đang bằng 5 cho nên b=ham1(5) bằng 5 )
  ( còn c thì đã được gán c=3 từ hàm trước cho nên vẫn giữ nguyên ) 


*/
