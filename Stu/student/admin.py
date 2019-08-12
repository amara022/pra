from django.contrib import admin
from .models import Student
admin.site.register(Student)

class BookAdmin(admin.ModelAdmin):
    list_display=('sid','sname','ssex','sage','sgrade','sscore')
    list_filter=['sid']
    search_fields=['bittle']

# Register your models here.
