## Simple Image Processing
Actually this is just the final homework of one of our courses, so if you are searching for something **useful** to process the image,please find **other packages!!!**

OK,if you are still interested in this package, I'd like to show you what I've done. Also, You can use this package just for fun.

### Usage
1. Image Rotation
2. Image Blurring
3. Image Compression
4. Image Encryption

### Attention
**Keep sure you have installed package "jpeg"** because we will just deal with the matrix instead of format conversion.

### Detailed function
#### 1. Image Rotation
e.x.

#### 4. Image Encryption
In this part, we realized two simple ways of encryption. 
#### Picture overlay
The first is a simple adding with two pictures, with this, you need to use the "source" picture and "mark" picture. If you want to send something to your brother without being found by your girlfriend, you and your brother can share the same "mark"(best with something blur), and when you send a picture difficult to distinguish(after encryption),only your brother can do the decryption.

e.x. 
```R
img=simpleEncryption(source,mark)
```
and your brother
```R
origin=simpleDecryption(img,mark)
```
#### Random Change of Points
The second is random change of the point, and you need to send your key matrix to your brother.

e.x.
```R
res=randomEncryption(source)
```
and your brother
```R
origin=randomDecryption(res$img,res$key)
```
