use std::io;
#[macro_use]
extern crate text_io;
use std::collections::BTreeMap;

fn main() {
    let q: u32 = read!();
    for _ in 0.. q {
        let num_cities: u32;
        let num_roads: u32;
        let cost_road: u32;
        let cost_lib: u32;
        scan!("{} {} {} {}", num_cities, num_roads, cost_road, cost_lib);
        let mut cities: Vec<usize> = Vec::new();
        cities.resize(num_cities as usize + 1, 0);
        for _ in 0..num_roads {
            let city_a: usize;
            let city_b: usize;
            scan!("{} {}", city_a, city_b);
            if cities[city_a] != 0 {
                cities[city_b] = cities[city_a];
            } else if cities[city_b] != 0 {
                cities[city_a] = cities[city_b];
            } else {
                cities[city_a] = city_a;
                cities[city_b] = city_a;
            }
        }

        let mut city_collections: BTreeMap<usize, u32> = BTreeMap::new();
        for city_root in 1..cities.len(){
            match city_collections.get(&city_root) {
                Some(count) => {
                    city_collections[&city_root] += 1;
                },
                None => {
                    city_collections.insert(city_root, 1);
                }
            }
        }

        if cost_lib > cost_road {
            let num_road_needed = num_cities - city_collections.len() as u32;
            let total_cost = city_collections.len() as u32 * cost_lib + num_road_needed * cost_road;
            println!("{}", total_cost);
        } else {
            println!("{}", num_cities * cost_lib);
        }
    }
}
