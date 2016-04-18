import csv
import random
import math
from .normalizer import Normalizer
from .cluster import Cluster
#from collections import OrderedDict

class KMeanClusterer():
	def __init__(self,k,n,p,path,c):
		self.k = k
		self.n = n
		self.p = p
		self.clusters = []
		
		n = Normalizer()
		self.observations = n.load_csv(path,c)

		self.performClustering()

		# sample = random.sample(self.observations,self.k);
		# for obs in sample:
		# 	self.clusters.append(Cluster(obs))

	def performClustering(self):
		#on crée les k clusters avec leurs centroids
		for obs in random.sample(self.observations,self.k):
			self.clusters.append(Cluster(obs))
		old=[]
		while tuple(self.getCentroids())!=tuple(old):
			old=self.getCentroids()
			self.assignement()
			self.update()
		print('Clustering Over.')
		print(' ')
		# while self.hasEmptyCluster():
		# 	self.assignementDone=False
		# 	self.clusters = []
		# 	sample = random.sample(self.observations,self.k);
		# 	for obs in sample:
		# 		self.clusters.append(Cluster(obs))
		# 	while not(self.assignement()):
		# 		self.update()

	def assignement(self):
		for cluster in self.clusters:
			cluster.emptyObs()
		for obs in self.observations:
			cluster = self.findNearestCluster(obs)
			cluster.addObservation(obs)
		summ=0
		print("Itération : ")
		for cluster in self.clusters:
			summ+=len(cluster.getObservations())
			print(str(len(cluster.getObservations()))+",",end="")
		print("["+str(summ)+"]")
		print()


	def update(self):
		for cluster in self.clusters:
			cluster.updateCentroid()
			# if len(cluster.getObservations())>0:
			# 	newCentroid=[0]*len(cluster.getCentroid())
			# 	for obs in cluster.getObservations():
			# 		for i in range(len(newCentroid)):
			# 			newCentroid[i]+=obs[i]
			# 	for i in range(len(newCentroid)):
			# 		newCentroid[i]/=float(len(cluster.getObservations()))
			# 	cluster.setCentroid(newCentroid)

	def getClusterNumber(self):
		return len(self.clusters)

	def getCluster(self,i):
		return self.clusters[i]

	def findNearestCluster(self,obs):
		nearestCluster=[]
		md=-1
		for cluster in self.clusters:
			d=cluster.getDistanceToCentroid(obs)
			if md!=-1 and d<md:
				md=d
				nearestCluster = cluster
			elif md==-1:
				md=d
				nearestCluster = cluster
		return nearestCluster

	def printClusters(self):
		i=1
		for cluster in self.clusters:
			print("cluster "+str(i)+" :")
			cluster.printCluster()
			print()
			i+=1

	def hasEmptyCluster(self):
		for cluster in self.clusters:
			if len(cluster.getObservations())==0:
				return True
		return False

	def getCentroids(self):
		centroids=[]
		for cluster in self.clusters:
			centroids.append(cluster.getCentroid())
		return centroids

	def returnTable(self):
		returnTable = []
		i=0
		for cluster in self.clusters:
			print("Appending Return Table...")
			returnTable.append(cluster.returnObservationTable(i,self.n,self.p))
			print("Appended !")
			i+=1
		return returnTable
