
import pandas as pd
from pandas import DataFrame

class medicaldiagnosis:
    def __init__(self):
        self.diagnosis=None
        self.symptoms=[]
        self.patients = pd.DataFrame(columns=["symptoms", "diagnosis"])

    def ask_questions(self,questions):
        answer=input(questions +"(yes/no)").strip().lower() 
        if answer=='yes'.lower():
            return True
        elif answer =='no'.lower():
            return False
        else:
            print("please enter yes or no")
            return self.ask_questions(questions)
    def asymptoms(self):
        if self.ask_questions("do you have fever?")  :
            self.symptoms.append('fever')  
        if self.ask_questions("do you have cold?"):
            self.symptoms.append('cold')    
        if self.ask_questions("do you have cough?"):
            self.symptoms.append('cough')
          

        self.patients = self.patients.append({"symptoms": ", ".join(self.symptoms), "diagnosis": ""}, ignore_index=True)


        if 'fever' in self.symptoms and 'cold' in self.symptoms:
            self.diagnosis = "you have a flu"
        elif 'fever' in self.symptoms and 'cough' in self.symptoms:
            self.diagnosis = "you have a viral infection"
        else:
            print("you are unclear please visit the doctor")     
    def run(self):
        print("welcome for medical ert system")
        self.asymptoms()
        print("diagnosis :",self.diagnosis)
        print("\n patient detail")
        print(self.patients)
if __name__=="__main__":
    s=medicaldiagnosis()
    s.run()        
