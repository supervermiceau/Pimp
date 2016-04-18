'''
Created on 24 mars 2015

@author: Pierre.Parrend
'''
import unittest
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

class Normalizer():
	def load_csv(self, dataFile, columns):
		# print("Load CSV from "+dataFile)
		self.columns = list(columns)
		self.data = []

		print(self.columns)

		d = open(dataFile,'r')
		reader = csv.reader(d)
		for row in reader:
			r=[]
			for i in self.columns:
				r.append(float(row[i]))
			self.data.append(r)
		# d.close()
		return self.normalize()
	
	def normalize(self):
		for i in range(len(self.data[0])):
			column=[]
			for row in self.data:
				column.append(row[i])
			mx = max(column)
			mn = min(column)
			for row in self.data:
				if mn!=mx:
					row[i] = 2*((row[i]-mn)/(mx-mn))-1
				else:
					row[i] = 0
		return self.data


class Test(unittest.TestCase):


    def setUp(self):
        pass


    def tearDown(self):
        pass

    def getDatasetSize(self, datafile):

        norm = Normalizer()
        iris_data_matrix = norm.load_csv(datafile)
        return len(iris_data_matrix)

    def testKMean(self):
        print("** test KMean **")
        
        # perform initialization
        k = 3
        datafile="iris.csv"
        kMeanClusterer = KMeanClusterer(k,datafile)
        kMeanClusterer.performClustering()
        
        #total number of lines in the dataset
        dataLines = 0
        norm = Normalizer()
        data_matrix = norm.load_csv(datafile)
        for row in data_matrix:
            if len(row) > 0:
                dataLines += 1

        #check the number of observations from dataset is kept        
        totalObsNb = 0
        for clusterNb in range(kMeanClusterer.getClusterNumber()):
            cluster = kMeanClusterer.getCluster(clusterNb)
            totalObsNb += len(cluster.getObservations())
        
        self.assertTrue(dataLines == totalObsNb, "Number of entries in dataset: "+str(dataLines)
                        +" is different from number of observations in cluster: "+str(totalObsNb))
        
        # check all entries in the dataset are kept
        index = 0
        for entry in data_matrix:
            found = False
            for clusterNb in range(kMeanClusterer.getClusterNumber()):
                cluster = kMeanClusterer.getCluster(clusterNb)
                observations = cluster.getObservations()
                for obs in observations:
                    if obs == entry:
                        found = True
            self.assertTrue(found, "observation "+str(entry)+" not found at index "+str(index))
            index += 1
            
    def testKMeanUpdate(self):
        print("** test KMean update **")
        
        k = 3
        datafile="../datasets/iris.csv"
        kMeanClusterer = KMeanClusterer(k,datafile)
        
        kMeanClusterer.assignement()
        kMeanClusterer.update()
        
        # check existence of centroid
        for i in range(kMeanClusterer.getClusterNumber()):
            current_cluster = kMeanClusterer.getCluster(i)
            self.assertTrue(len(current_cluster.getCentroid()) > 0, "void centroid for cluster "+str(i))
        
        # check validity of centroid
        for i in range(kMeanClusterer.getClusterNumber()):
            current_cluster = kMeanClusterer.getCluster(i)
            current_centroid = current_cluster.getCentroid()
            obs = current_cluster.getObservations()
            for j in range(len(current_centroid)):
                tmp = 0
                for i in range(len(obs)):
                    try:
                        tmp += float(obs[i][j])
                    except ValueError:
                        pass # field is not numeric
                try:
                    value = float(current_centroid[j])#for test that data is numeric
                    self.assertTrue(tmp/len(obs) == value, "current centroid: "+str(value)
                                +"; actual centroid value: "+str(tmp/len(obs)))
                except ValueError:
                        pass # field is not numeric

    def testarray_equility(self):
        print("** test array equility **")
            
        a = [5.1, 3.5, 1.4, 0.2]
        b = [5.1, 3.5, 1.4, 0.2]
        self.assertTrue(a == b, "a not equal to b")

if __name__ == "__main__":
    unittest.main()
