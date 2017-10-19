# coding=utf-8
"""A setuptools based setup module.
See:
https://packaging.python.org/en/latest/distributing.html
https://github.com/pypa/sampleproject
"""

# Always prefer setuptools over distutils
from setuptools import setup
# To use a consistent encoding
from codecs import open
from os import path

here = path.abspath(path.dirname(__file__))
info_file = 'DESCRIPTION.rst'

# Get the long description from the info_file
with open(path.join(here, info_file), encoding='utf-8') as f:
    long_description = f.read()

setup(
    name='gps3',

    # Versions should comply with PEP440.  For a discussion on single-sourcing
    # the version across setup.py and the project code, see
    # https://packaging.python.org/en/latest/single_source_version.html
    version='0.33.0',

    description='Python 2.7-3.5 clients for gpsd',
    long_description=long_description,

    # The project's main homepage.
    url='https://github.com/wadda/gps3',
    download_url='https://github.com/wadda/gps3/archive/master.zip',

    # Author details
    author='Moe',
    author_email='waddagit@wadda.org',

    # Choose your license
    license='MIT',

    # See https://pypi.python.org/pypi?%3Aaction=list_classifiers
    classifiers=['Development Status :: 4 - Beta',
                 'Environment :: Console',
                 'Environment :: Console :: Curses',
                 'Intended Audience :: Developers',
                 'Intended Audience :: Other Audience',
                 'Intended Audience :: Science/Research',
                 'License :: OSI Approved :: MIT License',
                 'Operating System :: OS Independent',
                 'Operating System :: POSIX',
                 'Programming Language :: Python :: 2.7',
                 'Programming Language :: Python :: 3',
                 'Programming Language :: Python :: 3.0',
                 'Programming Language :: Python :: 3.1',
                 'Programming Language :: Python :: 3.2',
                 'Programming Language :: Python :: 3.3',
                 'Programming Language :: Python :: 3.4',
                 'Programming Language :: Python :: 3.5',
                 'Topic :: Scientific/Engineering',
                 'Topic :: Scientific/Engineering :: GIS'
                 ],
    keywords=['gps', 'gpsd', 'developers'],

    # You can just specify the packages manually here if your project is
    # simple. Or you can use find_packages().
    packages=['gps3'],

    # Alternatively, if you want to distribute just a my_module.py, uncomment
    # this:
    # py_modules=['gps3'],

    # List run-time dependencies here.  These will be installed by pip when
    # your project is installed. For an analysis of "install_requires" vs pip's
    # requirements files see:
    # https://packaging.python.org/en/latest/requirements.html
    install_requires=[],

    # List additional groups of dependencies here (e.g. development
    # dependencies). You can install these using the following syntax,
    # for example:
    # $ pip install -e .[dev,test]
    # extras_require={
    #     'dev': ['check-manifest'],
    #     'test': ['coverage'],
    # },

    # If there are data files included in your packages that need to be
    # installed, specify them here.  If using Python 2.6 or less, then these
    # have to be included in MANIFEST.in as well.
    package_data={
        'gps3': ['examples/ahuman.py', 'examples/agegps3.py', 'examples/human.py', 'examples/gegps3.py']
    },

    # Although 'package_data' is the preferred approach, in some case you may
    # need to place data files outside of your packages. See:
    # http://docs.python.org/3.4/distutils/setupscript.html#installing-additional-files
    # In this case, 'data_file' will be installed into '<sys.prefix>/my_data'
    data_files=[('share/gps3/examples',
                 ['examples/ahuman.py',
                  'examples/agegps3.py',
                  'examples/human.py',
                  'examples/gegps3.py',
                  'examples/thread_example.py'])
                ],

    # To provide executable scripts, use entry points in preference to the
    # "scripts" keyword. Entry points provide cross-platform support and allow
    # pip to create the appropriate form of executable for the target platform.
    # entry_points={
    #     'console_scripts': [
    #         'sample=sample:main',
    #     ],
    # },
)
