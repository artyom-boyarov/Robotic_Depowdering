# How to run in Docker
## 1. Install docker engine and docker compose
Visit <a>https://docs.docker.com/engine/install/</a>.<br>
Then, visit <a>https://docs.docker.com/compose/install/linux/#install-using-the-repository</a>.

## 2. Build the images
```docker compose build```
## 3. Run the images
For example, if you want to get a container with ROS2 and gazebo available, run:<br>
```docker compose up -d dev``` <br>
```docker compose exec -it dev bash```<br>
Once you are in docker you have to run: <br>
```rosdep install --from-paths . --ignore-src --rosdistro humble -r -y```<br>

# TODO
Fix build directory sync