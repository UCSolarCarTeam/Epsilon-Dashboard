# Setup
Epsilon-Dashboard uses Conan to manage C++ dependencies and is required during build time. It also uses RabbitMQ as a messaging broker and is required during runtime. Both of these must be installed on your system if you wish to develop Epsilon-Dashboard.

# Conan
See [Conan's documentation](https://docs.conan.io/en/latest/installation.html#install-with-pip-recommended) for information on installing. Note that installing with Python/pip is **highly recommended**.

Once Conan is installed, some remotes need to be added as we use unofficial packages. Run the following commands to add the remotes:
* `conan remote add conan-dbelty https://api.bintray.com/conan/dbely/conan`

# RabbitMQ
TODO: Add instructions
