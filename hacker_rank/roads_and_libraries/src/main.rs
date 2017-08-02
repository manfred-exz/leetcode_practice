#[macro_use]
extern crate scan_rules;
fn main() {
    let mut q = String::new();
    std::io::stdin().read_line(&mut q).unwrap();
    let q: u32 = q.trim().parse::<u32>().unwrap();
    for _ in 0..q {
        let_readln!(let num_cities: u32, " ", let num_roads: u32, " ", let cost_lib: u32, " ", let cost_road: u32);
        let mut uf = UF::new(num_cities);
        for _ in 0..num_roads {
            let_readln!(let city_a: u32, " ", let city_b: u32);
            uf.union(city_a as usize -1, city_b as usize -1);
        }

//        println!("city_collections = {:?}", uf.count());

        if cost_lib > cost_road {
            let num_road_needed = num_cities - uf.count() as u32;
            let total_cost = uf.count() as u64 * cost_lib as u64 + num_road_needed as u64 * cost_road as u64;
            println!("{}", total_cost);
        } else {
            println!("{}", num_cities as u64 * cost_lib as u64);
        }
    }
}


struct UF {
    ids: Vec<u32>,
    count: u32,
}

impl UF {
    fn new(node_count: u32) -> UF {
        let mut ids: Vec<u32> = Vec::new();
        ids.resize(node_count as usize, 0);
        for i in 0..ids.len() {
            ids[i] = i as u32;
        }
        UF{
            ids: ids,
            count: node_count,
        }
    }

    fn count(&self) -> u32 {
        self.count
    }

    fn union(&mut self, p: usize, q: usize) {
        let p_id = self.find(p);
        let q_id = self.find(q);

        if p_id == q_id { return }
        self.ids[p_id as usize] = q_id;
        self.count -= 1;
    }

    fn find(&mut self, p: usize) -> u32 {
        let mut visitor = p as u32;
        while visitor != self.ids[visitor as usize] {
            visitor = self.ids[visitor as usize];
        }
        let mut p = p as u32;
        while p != visitor {
            let next = self.ids[p as usize];
            self.ids[p as usize] = visitor;
            p = next;
        }
        return visitor
    }
}