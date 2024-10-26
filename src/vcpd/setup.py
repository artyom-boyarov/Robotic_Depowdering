from setuptools import find_packages, setup

package_name = 'vcpd'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/cfg/', ['cfg/config.json']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='artyom',
    maintainer_email='artyom.boyarov@gmail.com',
    description='TODO: Package description',
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
