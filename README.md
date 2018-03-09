# TrAdaBoost

## 3.05
Through analysis, finally finding out that the feed in data is first in TFIDF format, and then transform to SVM input format.

So write the python file to generate it, using the 20News dataset.
### problems
Labels should NOT include [0].

Labels need both POSs and NEGs.

## 3.06
So what the xxxx of the calc_auc.exe really do? All the wired bugs points to this executable file...

Delete the enty in iter.bat of calc_auc blablabla, with questions and anger.

And meet a small data problem, nothing big.

## 3.07
Really slow(i7-2600k 3.6GHz), downshift the iterate nums and see if it is possible to reach the performance.

Result in the first iter:

    Scanning examples...done
    Reading examples into memory...100..200..300..400..500..600..700..800..900..1000..1100..1200..1300..1400..OK. (1498 examples read)
    Setting default regularization parameter C=1.0000
    Optimizing............done. (464 iterations)
    Optimization finished (1 misclassified, maxdiff=0.00094).
    Runtime in cpu-seconds: 11.21
    Number of SV: 847 (including 67 at upper bound)
    L1 loss: loss=12.81765
    Norm of weight vector: |w|=18.85134
    Norm of longest example vector: |x|=1.00000
    Estimated VCdim of classifier: VCdim<=356.37315
    Computing XiAlpha-estimates...done
    Runtime for XiAlpha-estimates in cpu-seconds: 0.05
    XiAlpha-estimate of the error: error<=4.47% (rho=1.00,depth=0)
    XiAlpha-estimate of the recall: recall=>97.13% (rho=1.00,depth=0)
    XiAlpha-estimate of the precision: precision=>94.64% (rho=1.00,depth=0)
    Number of kernel evaluations: 42986

# 3.08
Happy women's day

See the XiAlpha-estimate, precision shakes around 95%.

But in the outputfile, no result printed in vote_predict, obviously wrong outputs in results/results0/etc.txt, since the calc_auc executable file doesn't work for me, there is an error print in vote_auc.txt.

I think the prediction part is ok but the code is not showing us the intuitive or I missed something.

# 3.09
emmmm result file shows 2.5151e+266, do not known the mean.

vote_fmeasure file shows f-measure is 0, maybe some setup went wrong, or back to origin the input was wrong?