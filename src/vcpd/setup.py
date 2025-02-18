from setuptools import find_packages, setup
from glob import glob
package_name = 'vcpd'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/cfg/', ['cfg/config.json']),
        ('share/' + package_name + '/assets/grav/collision', glob('assets/grav/collision/*.obj')),
        ('share/' + package_name + '/assets/grav/visual', glob('assets/grav/visual/*.obj')),
        ('share/' + package_name + '/assets/', glob('assets/*.obj')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='artyom',
    maintainer_email='artyom.boyarov@gmail.com',
    description='Extension of the VCPD grasping library to support geometry- and physics-aware grasp evaluation and analysis',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'mesh_processing = vcpd.grasping.mesh_processing:main',
            'grasp_analysis = vcpd.grasping.grasp_analysis:main',
            'vcpd_service = vcpd.vcpd_service:main',
            'sample_vcpd_client = vcpd.sample_vcpd_client:main'
        ],
    },
)
