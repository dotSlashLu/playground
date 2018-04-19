import gevent
# from gevent import monkey; monkey.patch_all()
from gevent import socket
# import socket

BUFLEN = 2048
## server
server_so = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_so.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server_so.bind(('0.0.0.0', 10010))
server_so.listen(128)

def handle_recv(client_so):
    data = ''
    while True:
        # print 'waiting for client so to be ready for read'
        # gevent.socket.wait_read(client_so.fileno())
        recv_data = client_so.recv(BUFLEN)
        # print 'waiting for client so to be ready for write'
        # gevent.socket.wait_write(client_so.fileno())
        # client_so.sendall(recv_data)
        data += recv_data
        # print 'recved %s' % recv_data
        if not recv_data or len(recv_data) < BUFLEN:
            return data
        else:
            print 'incomplete'

def handle_conn(client_so, client_addr):
    host, port = client_addr
    data = handle_recv(client_so)
    print '%s:%s complete: %s' % (host, port, data)
    gevent.socket.wait_write(client_so.fileno())
    client_so.sendall(data)
    client_so.close()

while True:
    # print('wait for read')
    # gevent.socket.wait_read(server_so.fileno())
    client_so, client_addr = server_so.accept()
    # print 'accepted from %s:%s' % client_addr
    gevent.spawn(handle_conn, client_so, client_addr)
