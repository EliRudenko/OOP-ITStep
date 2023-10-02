#include "Camera.h"

Camera::Camera() {}

Camera::Camera(const std::string& inputN) : camera_n(inputN) {}

void Camera::set_camera_n(const std::string& inputN) { camera_n = inputN; }

const std::string& Camera::get_camera_n() const { return camera_n; }

Camera::~Camera() {}
