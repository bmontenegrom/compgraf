use std::fmt;
use std::ops::{Add, Sub, Mul, Div, Neg};

#[derive(Debug, Clone, Copy)]
struct Vec3 {
    x: f32,
    y: f32,
    z: f32,
    norm: f32,
}

impl Vec3 {
    fn new(x: f32, y: f32, z: f32) -> Vec3 {
        let norm = (x*x + y*y + z*z).sqrt();
        Vec3 { x, y, z, norm }
    }

    fn dot(&self, other: &Vec3) -> f32 {
        self.x * other.x + self.y * other.y + self.z * other.z
    }

    fn cross(&self, other: &Vec3) -> Vec3 {
        Vec3::new(
            self.y * other.z - self.z * other.y,
            self.z * other.x - self.x * other.z,
            self.x * other.y - self.y * other.x
        )
    }

    fn normalize(&self) -> Vec3 {
        Vec3::new(self.x / self.norm, self.y / self.norm, self.z / self.norm)
    }

    fn angle(&self, other: &Vec3) -> f32 {
        (self.dot(other) / (self.norm * other.norm)).acos()
    }

    fn norm(&self) -> f32 {
        self.norm
    }

    fn squared_norm(&self) -> f32 {
        self.norm * self.norm
    }

    fn simetric(&self, other: &Vec3) -> Self {
        2.0*(self.dot(other) / (self.norm * other.norm)) * other - *self
    }
}

impl Add for Vec3 {
    type Output = Self;

    fn add(self, other: Self) -> Self {
        Vec3::new(self.x + other.x, self.y + other.y, self.z + other.z)
    }
}

impl Sub for Vec3 {
    type Output = Self;

    fn sub(self, other: Self) -> Self {
        Vec3::new(self.x - other.x, self.y - other.y, self.z - other.z)
    }
}

impl Neg for Vec3 {
    type Output = Self;

    fn neg(self) -> Self {
        Vec3::new(-self.x, -self.y, -self.z)
    }
}

impl Mul<f32> for Vec3 {
    type Output = Self;

    fn mul(self, scalar: f32) -> Self {
        Vec3::new(self.x * scalar, self.y * scalar, self.z * scalar)
    }
}

impl Mul<&Vec3> for f32 {
    type Output = Vec3;

    fn mul(self, vec: &Vec3) -> Vec3 {
        Vec3::new(vec.x * self, vec.y * self, vec.z * self)
    }
}

impl Mul<Vec3> for f32 {
    type Output = Vec3;

    fn mul(self, vec: Vec3) -> Vec3 {
        Vec3::new(vec.x * self, vec.y * self, vec.z * self)
    }
}

impl Div<f32> for Vec3 {
    type Output = Self;

    fn div(self, scalar: f32) -> Self {
        Vec3::new(self.x / scalar, self.y / scalar, self.z / scalar)
    }
}

impl fmt::Display for Vec3 {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "({}, {}, {})", self.x, self.y, self.z)
    }
}




fn main() {
    println!("Ingrese un valor para x: ");
    let mut x = String::new();
    std::io::stdin().read_line(&mut x).unwrap();
    let x: f32 = x.trim().parse().unwrap();
    println!("Ingrese un valor para y: ");
    let mut y = String::new();
    std::io::stdin().read_line(&mut y).unwrap();
    let y: f32 = y.trim().parse().unwrap();
    println!("Ingrese un valor para z: ");
    let mut z = String::new();
    std::io::stdin().read_line(&mut z).unwrap();
    let z: f32 = z.trim().parse().unwrap();
    let v0 = Vec3::new(x, y, z);
    println!("Ingrese un valor para dt: ");
    let mut dt = String::new();
    std::io::stdin().read_line(&mut dt).unwrap();
    let dt: f32 = dt.trim().parse().unwrap();
    let mut  t = 0.0;
    let mut pos = Vec3::new(0.0, 0.0, 0.0);
    let g = Vec3::new(0.0, 0.0, -9.8);
    
    println!("Posicion: {} | Tiempo: {}", pos, t);
    while pos.z >= 0.0 {
        t += dt;
        pos = t*v0 + 0.5*t*t*g;
        println!("Posicion: {} | Tiempo: {}", pos, t);
    }
}
