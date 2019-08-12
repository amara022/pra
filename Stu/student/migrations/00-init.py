# Generated by Django 2.7

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Student',
            fields=[
                ('sid', models.AutoField(primary_key=True, serialize=False)),
                ('sname', models.CharField(blank=True, max_length=255, null=True)),
                ('ssex', models.CharField(blank=True, max_length=255, null=True)),
                ('sage', models.IntegerField(blank=True, null=True)),
                ('sgrade', models.CharField(blank=True, max_length=255, null=True)),
                ('sscore', models.IntegerField(blank=True, null=True)),
            ],
            options={
                'db_table': 'student',
                'managed': False,
            },
        ),
    ]
