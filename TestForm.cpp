//---------------------------------------------------------------------------

#include <fmx.h>
#include <queue>
#pragma hdrstop

#include "TestForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

class Question{
public:
	char* Text;
	char* Answer1;
	char* Answer2;
	char* Answer3;

	int correctAnswer;

	Question(){}

	Question(char* text, char* answer1, char* answer2, char* answer3, int correctAns){
		Text=text;
		Answer1=answer1;
		Answer2=answer2;
		Answer3=answer3;
		correctAnswer=correctAns;
	}

};

std::queue<Question> LoadQuestions(){
	Question q1=Question(" Cat face 1+1?", " Nu ", " Da ", " Ceva ", 3);
	Question q2=Question(" Ce este Dacia Logan?", " Golan ", " Naveta", " masina ", 2);
	Question q3=Question(" Cine este frate cu ironman?", "Batman", "CapitanuMexic", "Superman",3);

	std::queue<Question> questions;
	questions.push(q1);
	questions.push(q2);
	questions.push(q3);

	return questions;
}


std::queue <Question> questions;
Question currentQuestion;

int points=0;

int selectedAnswer;

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	questions = LoadQuestions();
	currentQuestion = questions.front();

	QuestionLabel -> Text = currentQuestion.Text;
	Answer1RadioButton -> Text = currentQuestion.Answer1;
	Answer2RadioButton -> Text = currentQuestion.Answer2;
	Answer3RadioButton -> Text = currentQuestion.Answer3;

	questions.pop();
	PointLabel -> Text = points;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Answer1RadioButtonChange(TObject *Sender)
{
	selectedAnswer=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Answer2RadioButtonChange(TObject *Sender)
{
	selectedAnswer=2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Answer3RadioButtonChange(TObject *Sender)
{
	selectedAnswer=3;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ConfirmButtonClick(TObject *Sender)
{
	if (selectedAnswer == currentQuestion.correctAnswer) {
		points++;
		PointLabel -> Text = points;
	}

	if(!questions.empty()){
		currentQuestion = questions.front();

		QuestionLabel -> Text = currentQuestion.Text;
		Answer1RadioButton -> Text = currentQuestion.Answer1;
		Answer2RadioButton -> Text = currentQuestion.Answer2;
		Answer3RadioButton -> Text = currentQuestion.Answer3;

		questions.pop();

		Answer1RadioButton -> IsChecked = false;
		Answer2RadioButton -> IsChecked = false;
		Answer3RadioButton -> IsChecked = false;
	}
	else{
		ConfirmButton -> Enabled = false;
		ConfirmButton -> Text = "Game Over";
	}
}
//---------------------------------------------------------------------------
