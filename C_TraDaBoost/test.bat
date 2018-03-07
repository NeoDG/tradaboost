@echo off

rinit > results.txt

for %%2 in (0 1 2 3 4 5 6 7 8 9) do (
	combine labeled_%1.tfidf unlabeled_%1.tfidf %2 %%253
	init train0.txt train1.txt 1 > train_weight.txt

	for %%1 in (00 01) do (
		call iter %%1 1
	)

	vote

	for %%1 in (00 01) do (
		fmeasure result_vote_predict_%%1.txt test.txt result_vote_fmeasure_%%1.txt
		calc_auc test.txt result_vote_predict_%%1.txt > result_vote_auc_%%1.txt
	)

	radd results.txt results_%%2.txt > results0.txt
	copy results0.txt results.txt
)

rfinal results.txt > results0.txt
copy results0.txt results.txt
