// map::find
#include <iostream>
#include <map>

int main ()
{
  /*int* ptr = new int[5]{5,4,3,2,1};

  std::cout<<"Address of the first element is "<<*ptr++<<std::endl;
  std::cout<<"Address of the second element is "<<*ptr++<<std::endl;
  std::cout<<"Address of the third element is "<<*ptr++<<std::endl;
  std::cout<<"Address of the fourth element is "<<*ptr++<<std::endl;*/

  int test[5] = {10,9,8,7,6};
  int (*a_ptr)[5] = &test;

  std::cout<<"Address of the the 1st array is "<<a_ptr<<std::endl;
  a_ptr++;
  std::cout<<"Address of the the 2nd array is "<<a_ptr<<std::endl;
  a_ptr--;
  std::cout<<"Address of the first element is "<<*a_ptr<<std::endl;
  std::cout<<"The value of the first element is "<<*((*a_ptr))<<std::endl;

  std::cout<<"Address of the second element is "<<(*a_ptr)<<std::endl;
  std::cout<<"The value of the second element is "<<*(*a_ptr)<<std::endl;


  std::cout<<"Address of the third element is "<<*a_ptr+2<<std::endl;
  std::cout<<"The value of the third element is "<<*(*a_ptr+2)<<std::endl;

  int* test2 = *a_ptr;

  std::cout<<"Test2 address is "<< *test2 <<std::endl;
  test2++;
  std::cout<<"Test2 address value is "<< *test2 <<std::endl;
  return 0;
}