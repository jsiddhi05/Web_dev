install.packages("ggplot2")
library(ggplot2)
ggplot(airquality,aes(x=Temp,y=Wind))+geom_line(size=0.1,col="red")
