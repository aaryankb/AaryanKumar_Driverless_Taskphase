from setuptools import find_packages
from setuptools import setup

setup(
    name='rt2_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('rt2_msgs', 'rt2_msgs.*')),
)
