class Normalizer

	def getMin(self):
		iris_file = "iris.csv"
		iris_data = open(iris_file, 'r')
		data = csv.reader(iris_data)
		iTmp=0
		for line in data:
			if line[1]<iTmp
				iTmp=line[1]
		return iTmp
		
	def getMax(self):
		iris_file = "iris.csv"
		iris_data = open(iris_file, 'r')
		data = csv.reader(iris_data)
		iTmp=0
		for line in data:
			if line[1]>iTmp
				iTmp=line[1]
		return iTmp
		
	def normalize(self):
		xmin=getMin()
		xmax=getMax()
		iris_file = "iris.csv"
		iris_data = open(iris_file, 'r')
		data = csv.reader(iris_data)
			for line in data:
				line[1] = 2 * ((line[1] - xmin) / xmax) - 1
	
	
