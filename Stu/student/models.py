# This is an auto-generated Django model module.
# You'll have to do the following manually to clean this up:
#   * Rearrange models' order
#   * Make sure each model has one field with primary_key=True
#   * Make sure each ForeignKey has `on_delete` set to the desired behavior.
#   * Remove `managed = False` lines if you wish to allow Django to create, modify, and delete the table
# Feel free to rename the models, but don't rename db_table values or field names.
from django.db import models


# 使用Terminal输入命令 python manage.py inspectdb > Student/models.py将数据库表生成实体类

class Student(models.Model):
    sid = models.AutoField(primary_key=True)
    sname = models.CharField(max_length=255, blank=True, null=True)
    ssex = models.CharField(max_length=255, blank=True, null=True)
    sage = models.IntegerField(blank=True, null=True)
    sgrade = models.CharField(max_length=255, blank=True, null=True)
    sscore = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'student'
