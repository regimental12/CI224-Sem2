
static glm::mat4 view_mat;
static glm::mat4 proj_mat;
static glm::vec3 ray_wor;



static bool rayCollision(Camera* cam ,  glm::vec3 ray, Cube* cube)
{    
    glm::vec3  dist_to_cube = cam->cameraPos - cube->getPosition();
    float b = glm::dot(cam->cameraPos , dist_to_cube);
    float c = glm::dot(dist_to_cube , dist_to_cube) - 1;
    float b_squared_minus_c = b*b - c;
    
    if (b_squared_minus_c < 2.0f)
    {
      std::cout << "ray hit!" <<std::endl;
      return true;
    }
      
    
    return false;
}

static glm::vec3 CalcRay(int x1 , int y1)
{
	  
	  float x = (2.0f * x) / 1366 - 1.0f;
	  float y = 1.0f - (2.0f *y) / 768;
	  float z = 1.0f;
	  // normalised device space
	  glm::vec3 ray_nds = glm::vec3 (x, y, z);
	  // clip space
	  glm::vec4 ray_clip = glm::vec4 (ray_nds.x, ray_nds.y, -1.0, 1.0);
	  // eye space
	  glm::vec4 ray_eye = glm::inverse (proj_mat) * ray_clip;
	  ray_eye = glm::vec4 (ray_eye.w, ray_eye.w, -1.0, 0.0);
	  // world space
	  ray_wor = glm::vec3 (glm::inverse (view_mat) * ray_eye);
	  // don't forget to normalise the vector at some point
	  ray_wor = glm::normalize (ray_wor);
	  std::cout << "clicky!" << std::endl;
	  return ray_wor;
}