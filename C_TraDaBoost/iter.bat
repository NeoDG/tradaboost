@echo off

build train.txt train_weight.txt > wtrain.txt
svm_learn wtrain.txt train.wmodel

@echo svm_classify train.txt train.wmodel train.predict0
@echo predict0 train.txt train.predict0 train.predict0 2 > train.predict
svm_classify train.txt train.wmodel train.predict

svm_classify test.txt train.wmodel predict.txt
predict0a train.txt predict.txt predict.txt 2 > result_svm_predict_%1.txt
@echo svm_classify test.txt train.wmodel result_svm_predict_%1.txt
calc_auc test.txt result_svm_predict_%1.txt > result_svm_auc_%1.txt
fmeasure result_svm_predict_%1.txt test.txt result_svm_fmeasure_%1.txt

reweight train.predict train.txt train_weight.txt 1 > train_weight_%1.txt
copy train_weight_%1.txt train_weight.txt
