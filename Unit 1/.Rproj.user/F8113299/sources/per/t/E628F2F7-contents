library(tidyr)

#gather() function wide to long 

#create data frame
wide_data=data.frame(
  id=1:3,
  math=c(67,98,34),
  science=c(78,45,23),
  english=c(56,90,23)
  
)
#gather to convert to long format
long_data=gather(wide_data,key="course",value ="marks",math:science)
View(long_data)
long_data1=data.frame(
  id=rep(1:3,each=3),
  subject=rep(c("maths","science","english"),times =3),
  score = c(67,98,34,78,45,23,56,90,23)
)
View(long_data1)
#spread ()convert long data format into wide data format.
wide_data1=spread(long_data,key="course",value="marks")
#View(wide_data1)
#spread to long data 


