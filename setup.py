from setuptools import setup, find_packages

setup(
    name='punictest',
    version='0.1.1',
    description='Simple unit testing for python',
    long_description=open('README.md').read(),
    long_description_content_type='text/markdown',
    author='Someone.',
    author_email='someonegithub@email.com',
    url='https://github.com/Somespi/Punic',
    packages=find_packages(),
    classifiers=[
        'Development Status :: 3 - Alpha',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
    ],
    keywords='unit testing test automation quality assurance software development'
)
