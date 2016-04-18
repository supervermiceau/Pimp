import math

class Cluster():
	def __init__(self,obs=None):
		self.observations = []
		self.centroid = []
		if(obs!=None):
			self.centroid = obs

	def addObservation(self,obs):
		self.observations.append(obs)

	def removeObservation(self,obs):
		self.observations.remove(obs)

	def setCentroid(self,obs):
		self.centroid=obs

	def getCentroid(self):
		return self.centroid

	def getDistanceToCentroid(self,obs):
		values = []
		for i in range(len(self.centroid)):
			values.append(math.pow(self.centroid[i]-obs[i],2))
		return math.sqrt(sum(values))

	def getObservations(self):
		return self.observations

	def printCluster(self):
		print("cluster : ",end="")
		print(len(self.observations))

	def emptyObs(self):
		self.observations=[]

	def updateCentroid(self):
		if len(self.observations)>0:
			newCentroid=[0]*len(self.centroid)
			for obs in self.observations:
				for i in range(len(newCentroid)):
					newCentroid[i]+=obs[i]
			for i in range(len(newCentroid)):
				newCentroid[i]/=float(len(self.observations))
			self.centroid = newCentroid

	def returnObservationTable(self,i,n,p):
		table=[]
		md=0
		for obs in self.observations:
			d=self.getDistanceToCentroid(obs)
			if d > md:
				md = d
		for obs in self.observations:
			a=0
			if self.getDistanceToCentroid(obs) >= ((100-n)/100)*md:
				a=1
			table.append([i]+obs+[a])
		table2=table[::int(100/p)]
		return table2