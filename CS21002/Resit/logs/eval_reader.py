from numpy import load
import os

dir = os.path.dirname(os.path.realpath(__file__))
eval = load(f"{dir}\\evaluations.npz")
contents = eval.files
for i in contents:
    print(i)
    print(eval[i])