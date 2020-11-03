import glob
from distutils.core import setup, Extension
from os.path import dirname

from setuptools import find_packages

__version__ = '0.1.0'

cpp_args = ['-std=c++14']

install_requires = [
]
setup_requires = ['pytest-runner']
tests_require = ['pytest', 'pytest-cov', 'mock']

PROJECT_ROOT = dirname(__file__)

stl_files = glob.glob(f"{PROJECT_ROOT}/stl/*.cpp")


ext_modules = [
    Extension(
        'stl',
        stl_files,
        include_dirs=['pybind11/include', 'utils'],
        language='c++',
        extra_compile_args=cpp_args,
    ),
]

setup(
    name='cppstl',
    version=__version__,
    description='Basic cpp stl extension',
    author='Mengqi Ye',
    author_email='mengqi.ye@anlogic.com',
    keywords=[
        'cppstl',
    ],
    python_requires='>=3.6',
    install_requires=install_requires,
    setup_requires=setup_requires,
    tests_require=tests_require,
    extras_require={'tests': tests_require},
    packages=find_packages(),
    include_package_data=True,
    ext_modules=ext_modules,
)
