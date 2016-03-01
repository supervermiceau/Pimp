from square import Square

import csv

def load_csv():
	iris_file = "iris.csv"
	iris_data = open(iris_file, 'r')
	data = csv.reader(iris_data)
	
	for line in data:
		print(line[1])
def run_array():
	
	my_array = [1, 2, 3, 4]
	print(my_array)
	last = my_array.pop()
	print(last)
	my_array.append(7)
	print(my_array)

def run_matrix():
	
	my_matrix = [[1,2],[3,4],[5,6]]
	print(my_matrix)
	
	for line in my_matrix:
		print(line)
		
def normalise(data):
	
	col1 = []
	col2 = []
	col3 = []
	col4 = []
	
	for line in data:
		try:
			col1.append[float(i[0])]
			col2.append[float(i[1])]
			col3.append[float(i[2])]
			col4.append[float(i[3])]
		except:
			pass
			
	min1= np.min(col1)
	min2= np.min(col2)
	min3= np.min(col3)
	min4= np.min(col4)
	
	max1= np.max(col1)
	max2= np.max(col2)
	max3= np.max(col3)
	max4= np.max(col4)
	
	for line in data:
		
	
	
	

if __name__== '__main__':
	print("Hello main method")

	my_square = Square()
	my_square.setSize(6)
	print("square surface: " + str(my_square.getSurface()))
	load_csv()

