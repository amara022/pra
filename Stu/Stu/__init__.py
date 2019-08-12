# 本文件在项目启动时会重新加载编译一次，在本项目导入pymsql之后，在这个文件里导入pymysql
import pymysql
# 将pymysql作为MySQLdb
pymysql.install_as_MySQLdb()
