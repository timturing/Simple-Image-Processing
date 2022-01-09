image_Palette <- function(img,r,g,b){
  
  img1 = img[ , , 1]
  img2 = img[ , , 2]
  img3 = img[ , , 3]
  
  nr <- dim(img)[1]
  nc <- dim(img)[2]
  nd <- dim(img)[3]
  
  imgg <- array( dim=c(nr,nc,nd) )
  
  imgg[ , , 1] = r * img1
  imgg[ , , 2] = g * img2
  imgg[ , , 3] = b * img3
  
  return (imgg)
}









































