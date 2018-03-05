# coding:utf-8
import os
import sys
from sklearn import feature_extraction
import numpy as np
import codecs
from sklearn.feature_extraction.text import TfidfTransformer
from sklearn.feature_extraction.text import CountVectorizer

corpus_train = []
n = 0
if __name__ == "__main__":
    for f in os.listdir('rec'):
        n += 1
        with codecs.open('rec/' + f, 'r') as f_train:
            corpus_train.append(' '.join(f_train.readlines()))
    for f in os.listdir('talk'):
        with codecs.open('talk/' + f, 'r') as f_train:
            corpus_train.append(' '.join(f_train.readlines()))
    # with codecs.open('talk.txt', 'r', 'utf-8') as f_test:
    #     corpus_test = [' '.join(f_test.readlines())]
    # with codecs.open('vocal.txt', 'r', 'utf-8') as v:
    #     vv = v.readlines()
    #     vocal0 = vv
    #     vocal1 = dict(zip(range(len(vv)), [0.0]*len(vv)))
    vectorizer = CountVectorizer()
    transformer = TfidfTransformer()
    tfidf = transformer.fit_transform(vectorizer.fit_transform(corpus_train))
    word = vectorizer.get_feature_names()  # 获取词袋模型中的所有词语
    weight = tfidf.toarray()  # 将tf-idf矩阵抽取出来，元素a[i][j]表示j词在i类文本中的tf-idf权重
    ran = np.arange(len(weight))
    np.random.shuffle(ran)
    with codecs.open('labeled_10.tfidf', 'w', 'utf-8') as f:
        # for i in range(len(vocal0)):
        #     if vocal0[i].strip() in word:
        #         vocal1[i] = weight[0][word.index(vocal0[i].strip())]
        #         f.write(str(i) + ' ' + str(vocal1[i]) + '\n')
        for i in ran[:10]:
            f.write(str(i + 1) + ' ' if i < n else str(-i - 1) + ' ')
            for j in range(len(weight[i])):
                f.write(str(j + 1) + ':' + str(weight[i][j]) + ' ')
            f.write('\n')
    with codecs.open('unlabeled_10.tfidf', 'w', 'utf-8') as f:
        for i in ran[n:n + 10]:
            f.write(str(i + 1) + ' ' if i < n else str(-i - 1) + ' ')
            for j in range(len(weight[i])):
                f.write(str(j + 1) + ':' + str(weight[i][j]) + ' ')
            f.write('\n')
