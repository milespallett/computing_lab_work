##Code adapted from article:https://www.geeksforgeeks.org/deep-learning/reinforcement-learning-using-pytorch/
##Along with the stable-baseline3 documentation pages https://stable-baselines3.readthedocs.io/en/master/modules/a2c.html and https://stable-baselines3.readthedocs.io/en/master/guide/quickstart.html
###Imports###
from MariNav.Env.MariNav import MariNav
import networkx as nx
import pandas as pd
from stable_baselines3 import A2C
from stable_baselines3.common.logger import configure
from stable_baselines3.common.callbacks import EvalCallback
import os

dir = os.path.dirname(os.path.realpath(__file__))

###Variable Delcarations###
#pairs taken from brief on mydundee
PAIRS = [('861909047ffffff','861956917ffffff')
         , ('861909047ffffff', '861956c77ffffff')
         , ('861956327ffffff', '86195665fffffff')
         , ('861956327ffffff', '861956917ffffff')
         , ('861956327ffffff', '861956c77ffffff')]
WIND_MAP_PATH = f'{dir}\\North_Channel_windmap.csv' #path to windmap csv file provided on mydundee
GRAPH_PATH = f'{dir}\\North_Channel_visits.gexf' #path to gexf file provided on mydundee

LOGGING_PATH = f'{dir}\\logs' #path for callback to log to


###Logger setup
tmp_path = "/tmp/sb3_log"
new_logger = configure(tmp_path, ["stdout", "csv", "tensorboard"])


###Functions###
#Based on https://gist.github.com/joaofig/c5123d2d36206aa85104f838eec896d8 -- UNUSED FUNCTION --
'''def graph_from_hexes(hexes):
    g = nx.Graph()
    for i in hexes:
        g.add_node(i)
    return g'''


###Main###

#create marinav environment
def create_env():
    env = MariNav(
        graph=nxGraph,
        wind_map=windmapDict,
        pairs=PAIRS
    )
    print("Environment created")
    return env


if __name__ == "__main__":
    print(f"Creating array of h3 cells from {GRAPH_PATH}...")
    #array of h3 cells, using networkx to extract nodes from gexf file provided on mydundee
    h3Array = nx.read_gexf(f"{GRAPH_PATH}").nodes

    print(f"Creating windmap dictionary from {WIND_MAP_PATH}... ")
    #dictionary created from windmap csv file provided on mydundee, using pandas to read csv and convert to dictionary
    windmapDict = pd.read_csv(f"{WIND_MAP_PATH}")
    windmapDict = pd.DataFrame.to_dict(windmapDict)

    print(f"Loading graph from {GRAPH_PATH}...")
    #networkx graph created from gexf file provided on mydundee, using networkx to read gexf file and convert to undirected graph
    nxGraph = nx.read_gexf(f"{GRAPH_PATH}").to_undirected()

    print(f"Creating environment...")
    mnEnv = create_env()

    #Evaluation
    evEnv = create_env()
    evCallback = EvalCallback(evEnv, best_model_save_path=f"{LOGGING_PATH}", log_path=f"{LOGGING_PATH}", eval_freq=500, deterministic=True, render=False)

    #Run and log model using A2C RL algorithm and stable-baseline3's MLP model policy
    model = A2C("MlpPolicy", mnEnv)
    model.set_logger(new_logger)
    model.learn(10000, callback=evCallback)

    #prints the current model policy for checking
    print("\n Outline of the policy used:")
    print(model.policy)
