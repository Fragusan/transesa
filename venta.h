//ejemplo
using namespace std;

class venta {
private:
    string nombre;
    string apellido ;
    int id, dni, telefono, asiento;
    bool pago; // true=efectivo false=virtual
    string fechaDeCompra, fechaDeViaje;
    enum horario {MANIANA, MEDIODIA, TARDE, NOCHE};
    enum estado {EN_ESPERA, CONCRETADO, CANCELADO};

    horario horaViaje;
    estado estadoVenta;

    public:
        // Constructor
        venta(string _nombre, string _apellido, int _id, int _dni, int _telefono, int _asiento,
               string _fechaDeCompra, string _fechaDeViaje, bool _pago,
               horario _horaViaje, estado _estadoVenta)
            : nombre(_nombre), apellido(_apellido), id(_id), dni(_dni), telefono(_telefono),
              asiento(_asiento), fechaDeCompra(_fechaDeCompra), fechaDeViaje(_fechaDeViaje),
              pago(_pago), horaViaje(_horaViaje), estadoVenta(_estadoVenta) {}
              
        
        venta(string _nombre, string _apellido, int _id, int _dni, int _telefono, int _asiento)
        : nombre(_nombre), apellido(_apellido), id(_id), dni(_dni), telefono(_telefono),
          asiento(_asiento), pago(true), // Pago predeterminado en efectivo
          fechaDeCompra("29/10/2024"), fechaDeViaje("02/11/2024"), // Fechas predeterminadas
          horaViaje(MANIANA), estadoVenta(EN_ESPERA) {}
          
          
        // Super Getters
        
        string getInfo() const {
        ostringstream detalles;
        detalles << "Nombre: " << nombre << "\n"
                 << "Apellido: " << apellido << "\n"
                 << "ID: " << id << "\n"
                 << "DNI: " << dni << "\n"
                 << "Teléfono: " << telefono << "\n"
                 << "Asiento: " << asiento << "\n"
                 << "Fecha de Compra: " << fechaDeCompra << "\n"
                 << "Fecha de Viaje: " << fechaDeViaje << "\n"
                 << "Método de Pago: " << (pago ? "Efectivo" : "Virtual") << "\n"
                 << "Hora de Viaje: " << getHoraViaje() << "\n"
                 << "Estado de Venta: " << getEstadoVenta() << "\n";
        return detalles.str();
    }
        
        //Getters
            string getNombre() const { return nombre; }
            string getApellido() const { return apellido; }
            int getId() const { return id; }
            int getDni() const { return dni; }
            int getTelefono() const { return telefono; }
            int getAsiento() const { return asiento; }
            string getFechaDeCompra() const { return fechaDeCompra; }
            string getFechaDeViaje() const { return fechaDeViaje; }
            string getPago() const {
                    return pago ? "Efectivo" : "Virtual";
                }
            string getHoraViaje() const {
                    switch (horaViaje) {
                        case MANIANA: return "MaÃ±ana";
                        case MEDIODIA: return "MediodÃ­a";
                        case TARDE: return "Tarde";
                        case NOCHE: return "Noche";
                        default: return "Desconocido";
                    }
                }

                string getEstadoVenta() const {
                    switch (estadoVenta) {
                        case EN_ESPERA: return "En espera";
                        case CONCRETADO: return "Concretado";
                        case CANCELADO: return "Cancelado";
                        default: return "Desconocido";
                    }
                }

            // Setters
            void setNombre(const string& _nombre) { nombre = _nombre; }
            void setApellido(const string& _apellido) { apellido = _apellido; }
            void setId(int _id) { id = _id; }
            void setDni(int _dni) { dni = _dni; }
            void setTelefono(int _telefono) { telefono = _telefono; }
            void setAsiento(int _asiento) { asiento = _asiento; }
            void setFechaDeCompra(const string& _fechaDeCompra) { fechaDeCompra = _fechaDeCompra; }
            void setFechaDeViaje(const string& _fechaDeViaje) { fechaDeViaje = _fechaDeViaje; }
            void setPago(bool _pago) { pago = _pago; }
            void setHoraViaje(horario _horaViaje) { horaViaje = _horaViaje; }
            void setEstadoVenta(estado _estadoVenta) { estadoVenta = _estadoVenta; }
            
};
