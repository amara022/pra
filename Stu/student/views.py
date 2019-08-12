from django.shortcuts import render
# 导入请求和响应的包
from django.shortcuts import HttpResponse
# 导入实体类所在的包
from student.models import Student
# 导入 redirect包（重定向）
from django.shortcuts import redirect
# 导入实体类的模块
from student import models
# 导入模糊查询
from django.db.models import Q
# 导入实体类
from student.models import Student


# Create your views here.

# 主页显示所有学生的信息
def showAll(request):
    # 测试向网页发送字符串
    # return HttpResponse("Hello world");
    # 查询所有数据库学生表的信息
    students = Student.objects.all()
    count = students.__len__()
    # 返回网页地址并携带学生数据
    return render(request, "index.html", context={"students": students, "count": count})


# 根据首页输入框模糊查询
def findStudent(request):
    # 获取搜索框的值
    str = request.POST.get("str")
    # 模糊查询(根据姓名或者性别或者年级查询)
    students = models.Student.objects.filter(
        Q(sname__icontains=str) | Q(ssex__icontains=str))
    # 获取数据的总条数
    count = students.__len__()
    return render(request, "index.html", context={"students": students, "count": count})


# 添加学生
def addStudent(request):
    if request.method == "GET":
        # 通过提交的方式判断
        # 如果是首页点击添加，则跳转到add.html页面
        return render(request, "add.html")
    else:
        # 如果是添加页面提交数据。则添加到数据库
        sname = request.POST.get("sname")
        ssex = request.POST.get("ssex")
        sage = request.POST.get("sage")
        sgrade = request.POST.get("sgrade")
        sscore = request.POST.get("sscore")
        # 使用Django框架提供的添加对象的方法
        Student.objects.create(sname=sname, ssex=ssex, sage=sage,sgrade=sgrade,sscore=sscore)
        # Student.objects.create(sname=sname)
        # 重定向到index.html
        return redirect("index.html")


# 修改学生
def updateStudent(request):
    # 根据表单提交的方式判断是查询单个还是修改之后提交数据库
    if request.method == "GET":
        # 获取要修改的对象的sid查询单个的学生
        sid = request.GET['update_sid']
        #  根据学生的sid查询单个学生进行修改
        student = Student.objects.get(sid=sid)
        # 跳转到修改页面，并携带修改对象的信息
        return render(request, "update.html", context={"student": student})
    # 表单提交，进行修改学生
    else:
        # 获取需要修改的学生对象的信息
        update_sid=request.POST.get("sid")
        update_student = Student.objects.get(sid=update_sid)
        update_sname=request.POST.get("sname")
        update_ssex=request.POST.get("ssex")
        update_sage=request.POST.get("sage")
        update_sgrade = request.POST.get("sgrade")
        update_sscore = request.POST.get("sscore")
        # 修改对象的信息
        update_student.sname=update_sname
        update_student.ssex=update_ssex
        update_student.sage=update_sage
        update_student.sgrade = update_sgrade
        update_student.sscore = update_sscore
        # 保存对象到数据库
        update_student.save()
        # 重定向到首页，显示学生信息
        return redirect("index.html")

# 删除学生
def deleteStudent(request):
    # 获取需要删除的学生对象的sid
    delete_sid=request.GET['delete_sid']
    # 先查找单个对象，然后进行删除
    Student.objects.get(sid=delete_sid).delete()
    # 删除之后，重定向到首页
    return redirect("index.html")


