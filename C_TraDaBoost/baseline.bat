@echo off

for %%1 in (0 1 2 3 4 5 6 7 8 9) do (
	combine task_a_labeled_%1.tfidf task_a_u00_%1.tfidf %2 %%153

	svm_learn train.txt train.model
	svm_classify test.txt train.model predict.txt
	fmeasure predict.txt test.txt fmeasure0_%%1.txt
	calc_auc test.txt predict.txt > auc0_%%1.txt

	svm_learn train1.txt train.model
	svm_classify test.txt train.model predict.txt
	fmeasure predict.txt test.txt fmeasure1_%%1.txt
	calc_auc test.txt predict.txt > auc1_%%1.txt

	svm_learn train2.txt train.model
	svm_classify test.txt train.model predict.txt
	fmeasure predict.txt test.txt fmeasure2_%%1.txt
	calc_auc test.txt predict.txt > auc2_%%1.txt
)


extract