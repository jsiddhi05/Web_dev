library(dplyr)

data1 = data.frame(dates=c("jan/11/2018","mar/11/2345","feb/2/2019"))
sep_data=separate(data1,col=dates,into=c("month","day","year"),sep="/")
View(sep_data)
