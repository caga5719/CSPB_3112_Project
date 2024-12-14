#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        bool no_students_want = true;
        int i = 0;
        //will need to loop through all students in the queue
        while(i < students.size()){
            //check if the a student at the front of the queue wants the sandwich at the top of the stack
            if (students[0] == sandwiches.front()){
                student_yes_sandwhich(students);
                student_yes_sandwhich(sandwiches);
                no_students_want = false;
                i--;
            //if a student doesn't want a sandwhich adjust the student queue to place them in the back
            } else {
                student_no_sandwhich(students);
            };
            // if we iterate through all students and no students want a sandwhich
            if(i == students.size() - 1 && no_students_want == true){
                break;
            // if we iterate through all students and at least one student wants
            } else if (i == students.size() - 1 && no_students_want == false){
                i = 0;
                no_students_want = true;
            } else{
                i++;
            }
        }
        return students.size();
    }

    //fucntion to adjust student queue when a student doesn't want a sandwhich
    void student_no_sandwhich(vector<int>& students){
        int front_stud = students[0];
        for(int i = 0; i < students.size() - 1;i++){
            //shifts the next index into the current index of the queue to remove the current head student in the queue and move everyone else up
            students[i] = students[i+1];
        }
            //places student at the front of the queue to the back.
            students[students.size()-1] = front_stud;
    }

    void student_yes_sandwhich(vector<int>& stack_or_queue){
        for(int i = 0; i < stack_or_queue.size() - 1;i++){
            stack_or_queue[i] = stack_or_queue[i+1];
        }
            stack_or_queue.pop_back();
    }

};