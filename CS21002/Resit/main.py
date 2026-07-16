##Code adapted from article:https://www.geeksforgeeks.org/deep-learning/reinforcement-learning-using-pytorch/
###Imports###
import gymnasium as gym
import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
from torch.distributions import Categorical
import matplotlib.pyplot
import h3
from MariNav.Env.MariNav import MariNav
import networkx as nx
import pandas as pd
import geopandas as gpd
import csv

###Variable Delcarations###
#pairs taken from brief on mydundee
pairs = [('861909047ffffff','861956917ffffff')
         , ('861909047ffffff', '861956c77ffffff')
         , ('861956327ffffff', '86195665fffffff')
         , ('861956327ffffff', '861956917ffffff')
         , ('861956327ffffff', '861956c77ffffff')]

#array of h3 cells, using networkx to extract nodes from gexf file provided on mydundee
h3Array = nx.read_gexf('CS21002\\North_Channel_visits.gexf').nodes

#dictionary created from windmap csv file provided on mydundee, using pandas to read csv and convert to dictionary
windmapDict = pd.read_csv('CS21002\\North_Channel_windmap.csv')
windmapDict = pd.DataFrame.to_dict(windmapDict)

#networkx graph created from gexf file provided on mydundee, using networkx to read gexf file and convert to undirected graph
nxGraph = nx.read_gexf('CS21002\\North_Channel_visits.gexf').to_undirected()


###Functions###
#Based on https://gist.github.com/joaofig/c5123d2d36206aa85104f838eec896d8 -- UNUSED FUNCTION --
'''def graph_from_hexes(hexes):
    g = nx.Graph()
    for i in hexes:
        g.add_node(i)
    return g'''


###Main###

#create marinav environment
env = MariNav(
    graph=nxGraph,
    wind_map=windmapDict,
    pairs=pairs
)
print("Environment created")
