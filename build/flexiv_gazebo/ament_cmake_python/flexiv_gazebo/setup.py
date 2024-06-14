from setuptools import find_packages
from setuptools import setup

setup(
    name='flexiv_gazebo',
    version='0.0.0',
    packages=find_packages(
        include=('flexiv_gazebo', 'flexiv_gazebo.*')),
)
