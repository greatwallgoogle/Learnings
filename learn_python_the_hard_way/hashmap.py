#定义自己的字典类
# 1. enumerate(list):将一个可遍历的数据对象(如列表、元组或字符串)组合为一个索引序列,
#    同时列出数据和数据下标，一般用在 for 循环当中。


def new(num_buckets = 256):
	"""Initializes a Map with the given number of buckets."""
	aMap = []
	for x in range(0,num_buckets):
		aMap.append([]) #!!!!!!
	return aMap

# 核心函数
def hash_key(aMap,key):
	"""Given a key this will create a number and then convert it 
	to an index for the aMap's buckets."""
	return hash(key) % len(aMap)


def get_bucket(aMap,key):
	"""Given a key,find the bucket where it would go."""
	bucket_id = hash_key(aMap,key)
	return aMap[bucket_id]

def get_slot(aMap,key,default = None):
	"""
	Returns the index,key and value of a slot found in a bucket.
	Returns -1,key, and default(None if not set) when not found.
	"""
	bucket = get_bucket(aMap,key)
	for i,kv in enumerate(bucket):
		k,v = kv
		if key == k:
			return i,k,v

	return -1,key,default


def get(aMap, key,default = None):
	"""Gets the value in a bucket for the given key,or the default."""
	i,k,v = get_slot(aMap,key,default = default)
	return v


def set(aMap,key,value):
	"""Sets the key to the value, replacing any existing value."""
	bucket = get_bucket(aMap,key)
	i,k,v = get_slot(aMap,key)

	if i >= 0:
		# the key exists, replace it
		bucket[i] = (key,value)
	else:
		#the key does not, append to create it
		bucket.append((key,value))


def delete(aMap,key):
	"""Deletes the given key from Map."""
	bucket = get_bucket(aMap,key)
	for x in xrange(len(bucket)):
		k,v = bucket[i]
		if key == k:
			del(bucketp[i])
			break


def printList(aMap):
	"""Prints out what's in the Map."""
	for bucket in aMap:
		if bucket:
			for k,v in bucket:
				print(k,v)






