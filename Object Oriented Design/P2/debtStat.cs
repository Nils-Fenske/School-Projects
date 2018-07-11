/*  Nils Fenske
    1/20/2016
    Programming Assignment 2
    debtStat class v1.3

Class Invariants
                                                                
Client does not know about this class. This class is encapsulated by the studenStat
class. 

================================================================================

Interface Invariants

Variable mutators for _loanIncrease and _loanDecrease allow for read only. In order
create a debtStat object user must pass in a valid 6 digit id, a start date and an
initial expected graduation date. User has access to anyother statistical info 
through public mehtods. 

================================================================================

Implementation Invariants

Loans and grants are stored in separate arrays private to the user. I wrote private
resize methods for each array.                                                                      

*/

namespace P2
{
    public class debtStat
    {
        private int _id;

        private int _loans;

        private int _grants;

        private int _startDate;

        private int _graduation;

        private int _amountPaid;

        private bool _status;

        private bool _gradExtend;

        private bool _loanIncrease;
        public bool loanIncrease
        {
            get
            {
                return _loanIncrease;
            }
        }

        private bool _loanDecrease;
        public bool loanDecrease
        {
            get
            {
                return _loanDecrease;
            }
        }

        private int[] _loanArr;

        private int[] _grantArr;

        private int _loanCount;

        private int _grantCount;

        // Precondition: Array of loans is full.
        // Postcondition: Array contains same data with twice the capacity.
        private void resizeLoans()
        {

            int initialSize = _loanArr.Length;

            int[] tempArr = new int[initialSize];

            for (int i = 0; i < initialSize; i++)
            {

                tempArr[i] = _loanArr[i];
            }

            _loanArr = new int[initialSize * 2];

            for (int i = 0; i < initialSize; i++)
            {

                _loanArr[i] = tempArr[i];
            }
        }

        // Precondition: Array of grants is full.
        // Postcondition: Array contains same data with twice the capacity.
        private void resizeGrants()
        {

            int initialSize = _grantArr.Length;

            int[] tempArr = new int[initialSize];

            for (int i = 0; i < initialSize; i++)
            {

                tempArr[i] = _grantArr[i];
            }

            _grantArr = new int[initialSize * 2];

            for (int i = 0; i < initialSize; i++)
            {

                _grantArr[i] = tempArr[i];
            }
        }

        // Precondition: User passes in valid id, start date, and graduation date.
        // Postcondition: DebtStat object is set in valid initial state with user entered id and dates, 
        //                values set to 0, booleans set to correct logic, empty arrays with initial size 10.
        public debtStat(int i, int s, int g)
        {

            _id = i;
            _startDate = s;
            _graduation = g;
            _status = true;
            _loans = 0;
            _grants = 0;
            _gradExtend = false;
            _loanIncrease = false;
            _loanDecrease = false;
            _amountPaid = 0;
            _loanArr = new int[10];
            _grantArr = new int[10];
            _loanCount = 0;
            _grantCount = 0;
        }

        // Precondition: Object has not been paid off (deactivated).
        // Postcondition: N/A
        public int debtTotal()
        {
            return _loans;
        }

        // Precondition: Object has not been paid off (deactivated). The passes a valid positive loan value. 
        // Postcondition: N/A
        public void addLoan(int x)
        {
            if (!_loanIncrease) { _loanIncrease = true; }

            _loans = _loans + x;
            _loanCount++;

            if (_loanCount == _loanArr.Length) { resizeLoans(); }

            _loanArr[_loanCount - 1] = x;
        }

        // Precondition: Object has not been paid off (deactivated).
        // Postcondition: N/A
        public int loanTotal()
        {
            return _loans;
        }

        // Precondition: Object has not been paid off (deactivated). The passes a valid positive grant value.
        // Postcondition: N/A
        public void addGrant(int x)
        {

            if (_status)
            {

                _grants = _grants + x;
                _grantCount++;

                if (_grantCount == _grantArr.Length) { resizeGrants(); }

                _grantArr[_grantCount - 1] = x;
            }
        }

        // Precondition: Object has not been paid off (deactivated). The passes a valid positive graduation extension value.
        // Postcondition: N/A
        public void extendGraduation(int numYears)
        {

            if (_status)
            {

                _graduation += numYears;

                if (!_gradExtend) { _gradExtend = true; }
            }
        }

        // Precondition: Object has not been paid off (deactivated). The passes a valid positive payment value <= debt amount.
        // Postcondition: N/A
        public void makePayment(int payment)
        {
            _loans -= payment;
            if (!_loanDecrease) { _loanDecrease = true; }

            _amountPaid += payment;
        }

        // Precondition: Object has not been paid off (deactivated). The passes a valid positive loan value >= 0.
        // Postcondition: N/A
        public bool testThreshold(int x)
        {
            return _loans > x;
        }

        // Precondition: Object has not been paid off (deactivated). The passes a valid positive loan value.
        // Postcondition: Object state will be false (deactivated).
        public void deactivate()
        {

            _status = false;
        }

        // Precondition: N/A
        // Postcondition: If object state is active will return true. If Object state is deactive will return false. 
        public bool isActive()
        {
            return _status;
        }

    }
}
