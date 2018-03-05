@echo off

rinit > results.txt

for %%2 in (0 1 2 3 4 5 6 7 8 9) do (
	combine labeled_%1.tfidf unlabeled_%1.tfidf %2 %%253
	init train0.txt train1.txt 1 > train_weight.txt

	for %%1 in (00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99) do (
		call iter %%1 1
	)

	vote

	for %%1 in (00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99) do (
		fmeasure result_vote_predict_%%1.txt test.txt result_vote_fmeasure_%%1.txt
		calc_auc test.txt result_vote_predict_%%1.txt > result_vote_auc_%%1.txt
	)

	radd results.txt results_%%2.txt > results0.txt
	copy results0.txt results.txt
)

rfinal results.txt > results0.txt
copy results0.txt results.txt
