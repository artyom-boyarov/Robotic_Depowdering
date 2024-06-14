from setuptools import find_packages
from setuptools import setup

setup(
    name='flexiv_msgs',
    version='0.10.0',
    packages=find_packages(
        include=('flexiv_msgs', 'flexiv_msgs.*')),
)
